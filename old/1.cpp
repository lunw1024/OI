#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Element
{
    int parent, l, r;
    Element(int parent = -1, int l = -1, int r = -1)
    {
        this->parent = parent;
        this->l = l;
        this->r = r;
    }
};


int N, R, C, x, y;
map<int, Element> rows[50001];
map<int, Element> cols[50001];

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int find(map<int, Element>& mp, int a)
{
    return mp[a].parent == a ? a : mp[a].parent = find(mp, mp[a].parent);
}

void merge(map<int, Element>& mp, int a, int b)
{
    int roota = find(mp, a), rootb = find(mp, b);
    mp[roota].parent = rootb;
    mp[rootb].l = min(mp[roota].l, mp[rootb].l);
    mp[rootb].r = max(mp[roota].r, mp[rootb].r);
}

void move(int direction)
{
    x += dx[direction];
    y += dy[direction];
    if (direction % 2 == 0)// in rows
    {
        map<int, Element>::iterator it = rows[x].find(y);
        if (it != rows[x].end())// visited
        {
            find(rows[x], y);// compress
            if (direction == 0)// right
            {
                y = rows[x][rows[x][y].parent].r + 1;
            }
            else if (direction == 2)// left
            {
                y = rows[x][rows[x][y].parent].l - 1;
            }
        }
    }
    else
    {
        map<int, Element>::iterator it = cols[y].find(x);
        if (it != cols[y].end())// visited
        {
            find(cols[y], x);// compress
            if (direction == 1)// up
            {
                x = cols[y][cols[y][x].parent].l - 1;
            }
            else if (direction == 3)// down
            {
                x = cols[y][cols[y][x].parent].r + 1;
            }
        }
    }

    // visit: create & merge
    rows[x][y] = Element(y, y, y);
    if (rows[x].find(y - 1) != rows[x].end())
    {
        merge(rows[x], y, y - 1);
    }
    if (rows[x].find(y + 1) != rows[x].end())
    {
        merge(rows[x], y, y + 1);
    }

    cols[y][x] = Element(x, x, x);
    if (cols[y].find(x - 1) != cols[y].end())
    {
        merge(cols[y], x, x - 1);
    }
    if (cols[y].find(x + 1) != cols[y].end())
    {
        merge(cols[y], x, x + 1);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        // reset & init
        if (i > 1)
        {
            for (int j = 1; j <= R; j++)
            {
                rows[j].clear();
            }
            for (int j = 1; j <= C; j++)
            {
                cols[j].clear();
            }
        }

        string s;
        cin >> N >> R >> C >> x >> y >> s;
        rows[x][y] = Element(y, y, y);
        cols[y][x] = Element(x, x, x);
        for (int j = 0; j < N; j++)
        {
            // move
            if (s[j] == 'E')
            {
                move(0);
            }
            else if (s[j] == 'N')
            {
                move(1);
            }
            else if (s[j] == 'W')
            {
                move(2);
            }
            else if (s[j] == 'S')
            {
                move(3);
            }
            cout << x << " " << y << endl;
        }
        cout << "Case #" << i << ": " << x << " " << y << endl;
    }
    cin.get();
    cin.get();
}