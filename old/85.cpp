#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int N;
pair<int, int> mat[1001][1001];
bool vis[1001][1001] = {0};
bool visited[1001][1001];

int dfs(int x, int y)
{
    
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (!visited[nx][ny])
        {

        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> mat[i][j].first >> mat[i][j].second;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; i++)
        {
            if (!vis[i][j])
            {
                vis[i][j] = true;
                if (mat[i][j] == make_pair(-1, -1))
                {
                    dfs1(i, j);
                }
                else
                {
                    fill(&visited[0][0], &visited[N - 1][N], false);
                    dfs(mat[i][j].first, mat[i][j].second);
                }
                
            }
        }
    }
}
