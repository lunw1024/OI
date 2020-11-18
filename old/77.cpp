#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N, T[2501], time_[2501], ans = 0;
bool vis[2501];
vector<int> edges[2501];
ifstream fin("clocktree.in");
ofstream fout("clocktree.out");

void dfs(int u, int parent)
{
    vis[u] = true;
    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i];
        if (!vis[v])
        {
            dfs(v, u);
        }
    }

    if (parent != u)
    {
        time_[parent] = (time_[parent] + 12 - time_[u]) % 12;
        time_[u] = 0;
    }
}

bool solve(int root)
{
    // init
    fill(vis + 1, vis + N + 1, false);
    for (int i = 1; i <= N; i++)
        time_[i] = T[i];
    
    dfs(root, root);

    // cout << time_[root] << endl;
    if (time_[root] == 0 || time_[root] == 1)
    {
        ans++;
    }
}

int main()
{
    fin >> N;
    for (int i = 1; i <= N; i++)
    {
        fin >> T[i];
        T[i] %= 12;
    }
    for (int i = 1; i <= N - 1; i++)
    {
        int a, b;
        fin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        solve(i);
    }
    
    fout << ans << endl;
    // system("pause");
}