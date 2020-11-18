#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

const int eps = 1e-5;

int sign(double x)
{
    return x > eps ? 1 : (x < -eps ? -1 : 0);
}

struct Point
{
    double x, y;

    Point(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    inline void print()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    Point operator+(const Point &o) const
    {
        return Point(x + o.x, y + o.y);
    }

    Point operator-(const Point &o) const
    {
        return Point(x - o.x, y - o.y);
    }

    Point operator*(const double &k) const
    {
        return Point(x * k, y * k);
    }

    Point operator/(const double &k) const
    {
        return Point(x / k, y / k);
    }

    double operator|(const Point &o) const
    {
        return x * o.x + y * o.y;
    }

    double operator^(const Point &o) const
    {
        return x * o.y - y * o.x;
    }

    double len()
    {
        return sqrt(x * x + y * y);
    }
};

double dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y + b.y) * (a.y + b.y));
}

struct Line
{
    Point a, b;

    Line(Point a, Point b)
    {
        this->a = a;
        this->b = b;
    }

    double len()
    {
        return dis(a, b);
    }
};

bool onl0(Point A, Line L)
{
    return sign((A - L.a) ^ (A - L.b)) == 0;
}

bool onl2(Point A, Line L)
{
    return sign((A - L.a) ^ (A - L.b)) == 0 &&
           sign(A.x - min(L.a.x, L.b.x)) >= 0 &&
           sign(A.y - min(L.a.y, L.b.y)) >= 0 &&
           sign(A.x - max(L.a.x, L.b.x)) <= 0 &&
           sign(A.y - max(L.a.y, L.b.y)) <= 0;
}

Point inter(Line L1, Line L2)
{
    double ls = (L1.b - L1.a) ^ (L2.a - L1.a);
    double rs = (L1.b - L1.a) ^ (L2.b - L1.a);
    return L2.a + (L2.b - L2.a) * ls / (ls - rs);
}

double disl0(Point A, Line L)
{
    return abs((L.a - A) ^ (L.b - A)) / dis(L.a, L.b);
}

double disl2(Point A, Line L)
{
    if (sign(A - L.a | L.b - L.a) < 0 || sign(A - L.b | L.a - L.b) < 0)
        return min(dis(A, L.a), dis(A, L.b));
    return disl0(A, L);
}

vector<Point> points;
vector<Line> lines;
bool vis[10] = {0};
int N = 0, ans = 0;

bool intersect(Line A, Line B)
{
    return sign((B.a - A.a) ^ (A.a - A.b)) == -sign((B.b - A.a) ^ (A.a - A.b)) &&
           sign((A.a - B.a) ^ (B.a - B.b)) == -sign((A.b - B.a) ^ (B.a - B.b));
}

void dfs(int p)
{
    vis[p] = true;
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        flag = flag && vis[i];
    }
    if (flag)
    {
        Line nl = Line(points[p], points[0]);
        for (int j = 0; j < lines.size(); j++)
        {
            if (intersect(nl, lines[j]))
            {
                flag = false;
            }
        }
        if (flag)
        {
            ans++;
        }
        vis[p] = false;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            bool flag = true;
            Line nl = Line(points[p], points[i]);
            for (int j = 0; j < lines.size(); j++)
            {
                // cout << lines.size() << N << endl;
                
                if (intersect(lines[j], nl))
                {
                    flag = false;
                }                
            }
            if (flag)
            {
                lines.push_back(nl);
                dfs(i);
                lines.pop_back();
            }
        }
    }
    vis[p] = false;
}

int main()
{
    int x, y;
    do
    {
        N++;
        cin >> x >> y;
        points.push_back(Point(x, y));
    } while (x != 0 || y != 0);

    dfs(0);

    cout << ans / 2 << endl;
    // system("pause");
}
