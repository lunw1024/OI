#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

const int MAXN = 302;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int N, M;
int h[MAXN][MAXN] = {0};
bool leak[MAXN * MAXN] = {0}, vis[MAXN][MAXN] = {0};
int fa[MAXN * MAXN]; // encoding: x * MAXN + y
vector<pair<int, int> > seq; // (h, id)

inline int encode(int x, int y)
{
    return x * MAXN + y;
}

inline pair<int, int> decode(int id)
{
    return make_pair(id / MAXN, id % MAXN);
}

int ufs_find(int x)
{
    return fa[x] == x ? x : (fa[x] = ufs_find(fa[x]));
}

void ufs_merge(int a, int b)
{
    int roota = ufs_find(a), rootb = ufs_find(b);
    // if (roota == rootb)
    //     cout << "ERROR!" << endl;
    fa[roota] = rootb;
}

inline bool safe(int x, int y)
{
    return x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1;
}

void bfs(int x, int y)
{
    vis[x][y] = true;
    // find and merge same height
    queue<pair<int, int> > que;
    que.push(make_pair(x, y));
    int group = encode(x, y);
    while (!que.empty())
    {
        pair<int, int> p = que.front();
        que.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = p.first + dx[dir], ny = p.second + dy[dir];
            if (!safe(nx, ny))
                continue;
            
            if (leak[ufs_find(encode(nx, ny))] && h[nx][ny] <= h[x][y])
            {
                leak[group] = true;
            }
            else if (h[nx][ny] < h[x][y])
            {
                ufs_merge(encode(nx, ny), group);
            }
            else if (h[nx][ny] == h[x][y] && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                ufs_merge(encode(nx, ny), group);
                que.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= M + 1; j++)
        {
            if (i >= 1 && i <= N && j >= 1 && j <= M)
                cin >> h[i][j];
            seq.push_back(make_pair(h[i][j], encode(i, j)));
        }
        
    }

    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= M + 1; j++)
        {
            fa[encode(i, j)] = encode(i, j);
            if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
            {
                leak[encode(i, j)] = true;
            }
        }
        
    }

    sort(seq.begin(), seq.end());

    for (int i = 0; i < seq.size(); i++)
    {
        pair<int, int> p = decode(seq[i].second);
        if (!vis[p.first][p.second])
        {
            bfs(p.first, p.second);
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            pair<int, int> root = decode(ufs_find(encode(i, j)));
            cout << h[root.first][root.second] - h[i][j] << " ";
        }
        cout << endl;
    }
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //     {
    //         pair<int, int> root = decode(ufs_find(encode(i, j)));
    //         cout << "(" << root.first << ", " << root.second << ") ";
    //     }
    //     cout << endl;
    // }
    // system("pause");
    
}