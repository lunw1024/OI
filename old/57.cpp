#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

const int MAXN = 50, MAXM = 10000;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};
int N, M;
string s;
char mat[MAXN][MAXM];
int dist[MAXN][MAXM];
pair<int, int> next_[MAXN][MAXM][4];
queue<pair<int, int>> start, que;

inline int get_dist(pair<int, int> p)
{
    return dist[p.first][p.second];
}

inline bool safe(pair<int, int> p)
{
    return p.first >= 0 && p.first < N && p.second >= 0 && p.second < M;
}

void preprocess()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int x = i, y = j;
                while (safe(make_pair(x + dx[dir], y + dy[dir])))
                {
                    x += dx[dir], y += dy[dir];
                    if (mat[x][y] != mat[i][j])
                    {
                        break;
                    }
                }
                next_[i][j][dir] = make_pair(x, y);
            }
        }
        
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> s;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == s[0])
            {
                start.push(make_pair(i, j));
            }
        }
    }

    for (int len = 0; len < s.size(); len++)
    {
        pair<int, int> top;
        if (!start.empty() && (que.empty() || get_dist(start.front()) > get_dist(que.front())))
        {
            top = start.front();
            dist[top.first][top.second] = 0
        }
        else if (!que.empty())
        {
            top = que.front();
        }
        else
        {
            cout << "ERROR" << endl;
        }
        
        for (int dir = 0; dir < 4; dir++)
        {

        }

        // init
        fill(&dist[0][0], &dist[MAXN - 1][MAXM], 999999);
    }
    
}