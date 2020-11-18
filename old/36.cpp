#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct Element
{
    int x, y, d, dis;
    Element(int x, int y, int d, int dis)
    {
        this->x = x;
        this->y = y;
        this->d = d;
        this->dis = dis;
    }

    bool operator<(const Element& o) const
    {
        return this->dis > o.dis;
    }
};

const int MAXN = 32;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int N, M, Q;
bool canMove[MAXN][MAXN] = {0};
int edges[MAXN][MAXN][4][4]; // (x, y, d) -> (x, y, d')

int bfsdist[MAXN][MAXN];
int dist[MAXN][MAXN][4];
priority_queue<Element> que;

// connect edges from (x, y, d) to (x, y, d')
void bfs(int x, int y, int d) 
{
    // init
    fill(&bfsdist[0][0], &bfsdist[N][M + 1], (int)1e9);
    queue<pair<int, int> > bfsque;
    bfsque.push(make_pair(x + dx[d], y + dy[d]));
    bfsdist[x + dx[d]][y + dy[d]] = 0;
    canMove[x][y] = false; // need reset

    // bfs
    while (!bfsque.empty())
    {
        pair<int, int> top = bfsque.front();
        bfsque.pop();
        int x = top.first, y = top.second;
        for (int dir = 0; dir < 4; dir++)
        {
            if (canMove[x + dx[dir]][y + dy[dir]] && bfsdist[x + dx[dir]][y + dy[dir]] > bfsdist[x][y] + 1)
            {
                bfsdist[x + dx[dir]][y + dy[dir]] = bfsdist[x][y] + 1;
                bfsque.push(make_pair(x + dx[dir], y + dy[dir]));
            }
        }
    }
    canMove[x][y] = true;

    // connect edges
    for (int nd = 0; nd < 4; nd++)
    {
        if (canMove[x + dx[nd]][y + dy[nd]] && bfsdist[x + dx[nd]][y + dy[nd]] < (int)1e9 && d != nd) // impossible edges == -1
        {
            edges[x][y][d][nd] = bfsdist[x + dx[nd]][y + dy[nd]];
        }
    }
}

void bfs2(int sx, int sy, int ex, int ey)
{
    // init
    fill(&bfsdist[0][0], &bfsdist[N][M + 1], (int)1e9);
    queue<pair<int, int> > bfsque;
    bfsque.push(make_pair(ex, ey));
    bfsdist[ex][ey] = 0;
    canMove[sx][sy] = false; // remember to reset

    // bfs
    while (!bfsque.empty())
    {
        pair<int, int> top = bfsque.front();
        bfsque.pop();
        int x = top.first, y = top.second;
        for (int dir = 0; dir < 4; dir++)
        {
            if (canMove[x + dx[dir]][y + dy[dir]] && bfsdist[x + dx[dir]][y + dy[dir]] > bfsdist[x][y] + 1)
            {
                bfsdist[x + dx[dir]][y + dy[dir]] = bfsdist[x][y] + 1;
                bfsque.push(make_pair(x + dx[dir], y + dy[dir]));
            }
        }
    }
    canMove[sx][sy] = true;

    // init states for dijkstra
    for (int d = 0; d < 4; d++)
    {
        dist[sx][sy][d] = bfsdist[sx + dx[d]][sy + dy[d]];
        que.push(Element(sx, sy, d, dist[sx][sy][d]));
    }
}

void dijkstra(int sx, int sy, int tx, int ty, int ex, int ey)
{
    if (sx == tx && sy == ty) // 差一点一次过 好气哦
    {
        cout << 0 << endl;
        return;
    }

    // init
    while (!que.empty())
    {
        que.pop();
    }
    fill(&dist[0][0][0], &dist[N + 1][M + 1][4], 1e9);
    bfs2(sx, sy, ex, ey);

    while (!que.empty())
    {
        Element top = que.top();
        que.pop();
        int x = top.x, y = top.y, d = top.d, dis = top.dis;
        if (dist[x][y][d] != dis)
        {
            continue;
        }

        // move vacancy
        for (int nd = 0; nd < 4; nd++)
        {
            if (edges[x][y][d][nd] != -1 && canMove[x + dx[nd]][y + dy[nd]] && dist[x][y][nd] > dist[x][y][d] + edges[x][y][d][nd])
            {
                dist[x][y][nd] = dist[x][y][d] + edges[x][y][d][nd];
                que.push(Element(x, y, nd, dist[x][y][nd]));
            }
        }

        // move block
        if (dist[x + dx[d]][y + dy[d]][(d + 2) % 4] > dist[x][y][d] + 1)
        {
            dist[x + dx[d]][y + dy[d]][(d + 2) % 4] = dist[x][y][d] + 1;
            que.push(Element(x + dx[d], y + dy[d], (d + 2) % 4, dist[x][y][d] + 1));
        }
    }

    int ans = 1e9;
    for (int d = 0; d < 4; d++)
    {
        ans = min(ans, dist[tx][ty][d]);
    }
    cout << (ans < (int)1e9 ? ans : -1) << endl;
    
    // // DEBUG
    // if (ans == 2654)
    // {
    //     for (int i = 0; i <= N + 1; i++)
    //     {
    //         for (int j = 0; j <= M + 1; j++)
    //         {
    //             cout << dist[i][j][1] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
}

int main()
{
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> canMove[i][j];
        }
    }

    fill(&edges[0][0][0][0], &edges[MAXN - 1][MAXN - 1][3][4], -1);

    // connect edges with len > 1
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (canMove[i][j])
            {
                for (int d = 0; d < 4; d++)
                {
                    if (canMove[i + dx[d]][j + dy[d]]) // unexisted state has 0 out degree and 0 in degree
                    {
                        bfs(i, j, d);
                    }
                }
            }
        }
    }

    for (int q = 0; q < Q; q++)
    {
        int ex, ey, sx, sy, tx, ty;
        cin >> ex >> ey >> sx >> sy >> tx >> ty;

        dijkstra(sx, sy, tx, ty, ex, ey);
    }
    // system("pause");
}