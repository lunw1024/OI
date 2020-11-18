#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int N, M, cnt = 0;
vector<int> edges[1001];
bool ans[1001] = {0};
int indegree[1001] = {0};
bool vis[1001] = {0};

int outdegree(int u)
{
    int out = 0;
    for (int v : edges[u])
    {
        if (indegree[v] > 0)
            out++;
    }
    return out;
}

void topo_sort()
{
    queue<int> que;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            que.push(i);
    }
    while (!que.empty())
    {
        int top = que.front();
        que.pop();
        for (int v : edges[top])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                que.push(v);
        }
    }

    for (int i = 1; i <= N; i++)
        if (indegree[i] > 0)
            cnt++;
}

void strip()
{
    for (int i = 1; i <= N; i++)
        if (indegree[i] > 0 && !ans[i])
        {
            indegree[i] = 0, cnt--;
            for (int v : edges[i])
                indegree[v] = max(0, indegree[v] - 1);
        }

    for (int i = 1; i <= N; i++)
        if (indegree[i] > 0 && outdegree(i) == 0)
        {
            indegree[i] = 0, cnt--;
            for (int v : edges[i])
                indegree[v] = max(0, indegree[v] - 1);
        }
}

// vis isn't cleared
bool dfs(int u, int depth, int root)
{
    vis[u] = true;
    for (int v : edges[u])
    {
        if (indegree[v] == 0)
            continue;
        if (!vis[v])
        {
            if (dfs(v, depth + 1, root))
            {
                ans[u] = true;
                return true;
            }
        }
        else if (v == root && depth < cnt)
        {
            ans[u] = true;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        indegree[b]++;
    }

    topo_sort();

    for (int i = 1; i <= N; i++)
        if (indegree[i] > 0)
            ans[i] = true;
    strip();
    for (int i = 1; i <= N; i++)
        if (indegree[i] > 0)
            ans[i] = true;
        else
            ans[i] = false;

    while (true)
    {
        strip();
        // for (int i = 1; i <= N; i++)
        //     cout << indegree[i] << " ";
        // cout << endl;

        int root = 0;
        for (int i = 1; i <= N; i++)
            if (indegree[i] > 1)
                root = i;
        if (root == 0)
            break;
        
        fill(ans + 1, ans + 1 + N, false);
        fill(vis + 1, vis + 1 + N, false);
        dfs(root, 1, root);
    }
    
    if (cnt == 0)
        cout << -1 << endl;
    else
    {
        cout << cnt << endl;
        for (int i = 1; i <= N; i++)
        {
            if (ans[i])
                cout << i << endl;
        }
    }
    system("pause");
}