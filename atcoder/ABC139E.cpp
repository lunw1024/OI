#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1001;
int N, indegree[MAXN][MAXN] = {0};
vector<pair<int, int>> edges[MAXN][MAXN];

int solve()
{
    int out = 0;
    queue<pair<int, int>> que[2];
    for (int i = 1; i <= N - 1; i++)
        for (int j = i + 1; j <= N; j++)
            if (indegree[i][j] == 0)
                que[0].push(make_pair(i, j));

    bool flag = true;
    while (flag)
    {
        flag = false;
        while (!que[out % 2].empty())
        {
            pair<int, int> top = que[out % 2].front();
            que[out % 2].pop();
            for (pair<int, int> v : edges[top.first][top.second])
            {
                indegree[v.first][v.second]--;
                if (indegree[v.first][v.second] == 0)
                    que[(out + 1) % 2].push(make_pair(v.first, v.second));
            }
            flag = true;
        }
        if (flag)
            out++;
    }

    // check loop
    for (int i = 1; i <= N - 1; i++)
        for (int j = i + 1; j <= N; j++)
            if (indegree[i][j] > 0)
                out = -1;

    return out;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int prev;
        cin >> prev;
        for (int j = 2; j <= N - 1; j++)
        {
            int v;
            cin >> v;
            edges[min(i, prev)][max(i, prev)].push_back(make_pair(min(i, v), max(i, v)));
            indegree[min(i, v)][max(i, v)]++;
            prev = v;
        }
    }

    cout << solve() << endl;
    // system("pause");
}