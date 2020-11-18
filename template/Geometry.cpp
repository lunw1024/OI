#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int eps = 1e-5;

int sign(double x)
{
    return x > eps ? 1 : (x < -eps ? -1 : 0);
}

double dis(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y + b.y) * (a.y + b.y));
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

