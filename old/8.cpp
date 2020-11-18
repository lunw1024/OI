#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

int N, M, H[500][500] = {0};
bool visited[500][500] = {0};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
pair<int, int> cache[500][500];

int bfs()
{
    queue<pair<int, int> > que;
    for (int i = 0; i < M; i++)
    {
        que.push(make_pair(0, i));
        visited[0][i] = true;
    }
    while (!que.empty())
    {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M || visited[x + dx[i]][y + dy[i]])
            {
                continue;
            }
            if (H[x + dx[i]][y + dy[i]] < H[x][y])
            {
                que.push(make_pair(x + dx[i], y + dy[i]));
                visited[x + dx[i]][y + dy[i]] = true;
            }
        }
    }

    int out = 0;
    for (int i = 0; i < M; i++)
    {
        if (!visited[N - 1][i])
        {
            out++;
        }
    }
    return out;
}

pair<int, int> dfs(int x, int y)
{
    visited[x][y] = true;
    pair<int, int> out = make_pair(1000, -1);
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> temp;
        if (x + dx[i] < 0 && x + dx[i] >= N && y + dy[i] < 0 && y + dy[i] >= M)
        {
            continue;
        }
        if (H[x + dx[i]][y + dy[i]] < H[x][y] && !visited[x + dx[i]][y + dy[i]])
        {
            temp = dfs(x + dx[i], y + dy[i]);
        }
        else if (H[x + dx[i]][y + dy[i]] < H[x][y])
        {
            temp = cache[x + dx[i]][y + dy[i]];
        }
        out.first = min(out.first, temp.first);
        out.second = max(out.second, temp.second);
        cache[x][y] = out;
    }
    return out;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> H[i][j];
        }
    }

    int lack = bfs();
    if (lack > 0)
    {
        cout << 0 << endl << lack << endl;
        return 0;
    }

    fill(&visited[0][0], &visited[499][500], false);
    
    vector<pair<int, int> > segments;
    for (int i = 0; i < M; i++)
    {
        segments.push_back(dfs(0, i));
    }

    cout << "hi";

    int p = 0, ans = 0;
    while (p < M)
    {
        int maximum = -1000;
        for (int i = 0; i < M; i++)
        {
            cout << "seg[" << i << "] = (" << segments[i].first << ", " << segments[i].second << ")" << endl; 
            if (segments[i].first <= p)
            {
                maximum = max(maximum, segments[i].second);
            }
        }
        ans++;
        p = maximum + 1;
    }
    
    // output
    cout << 1 << endl << ans << endl;
    system("pause");
}