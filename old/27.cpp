#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 10001;
int N, M;
int w[MAXN], wscc[MAXN], dfn[MAXN] = {0}, low[MAXN], belong[MAXN] = {0}, time = 0, cnt = 0;
vector<int> graph[MAXN], new_graph[MAXN];
int stk[MAXN], top = 0;

void tarjan(int x)
{
    low[x] = dfn[x] = ++time;
    for (vector<int>::iterator it = graph[x].begin(); it != graph[x].end(); it++)
    {
        if (dfn[*it] == 0)
        {
            tarjan(*it);
            low[x] = min(low[x], low[*it]);
        }
        else if (belong[*it] == 0)// in stack
        {
            low[x] = min(low[x], dfn[*it]);
        }
    }
    if (dfn[x] == low[x])
    {
        cnt++;
        int y;
        while (y = stk[top--])
        {
            belong[y] = cnt;
            wscc[cnt] += w[y];
            if (x == y)
                break;
        }
    }
}

int indegree[MAXN] = {0};
queue<int> que;
int dp[MAXN] = {0}, ans = 0;

void topo_sort()
{
    for (int i = 1; i <= cnt; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
            dp[i] = wscc[i];
            ans = max(ans, dp[i]);
        }

        while (!que.empty())
        {
            int top = que.front();
            que.pop();
            for (vector<int>::iterator it = new_graph[top].begin(); it != new_graph[top].end(); it++)
            {
                indegree[*it]--;
                if (indegree[*it] == 0)
                {
                    que.push(*it);
                }

                dp[*it] = max(dp[*it], dp[i] + wscc[*it]);
                ans = max(ans, dp[*it]);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= N; i++)
        if (dfn[i] == 0)
            tarjan(i);

    for (int i = 1; i <= N; i++)
    {
        for (vector<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
        {
            if (belong[i] != belong[*it])
            {
                new_graph[belong[i]].push_back(belong[*it]);
                indegree[belong[*it]]++;
            }
        }
    }

    topo_sort();
    cout << ans << endl;
    system("pause");

}