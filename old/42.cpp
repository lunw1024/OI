#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
typedef long long ll;

const int MAXN = 1001;
int N, M, C, lim;
int weight[MAXN];
bool vis[MAXN] = {0};
vector<int> edges[MAXN];
int ans[1001] = {0};
int dp[1001] = {0};
ifstream fin("time.in");
ofstream fout("time.out");

void dfs(int u, int sum, int t)
{
    // cout << u << " " << sum << " " << t << endl;
    vis[u] = true;
    if (u == 1)
    {
        ans[t] = max(ans[t], sum);
        if (t > 0)
        {
            return;
        }
    }        

    if (t > lim)
    {
        vis[u] = false;
        return;
    }

    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i];
        if (!vis[v] || v == 1)
            dfs(v, sum + weight[v], t + 1);
    }
    vis[u] = false;
}

int main()
{
    fin >> N >> M >> C;
    lim = (int)(1000 / C + 1) / 2;
    // cout << "lim = " << lim << endl;
    for (int i = 1; i <= N; i++)
    {
        fin >> weight[i];
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        fin >> a >> b;
        edges[a].push_back(b);

    }

    dfs(1, 0, 0);

    // dp
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            dp[j] = max(dp[j], dp[j - i] + ans[i]);
        }
    }

    int maximum = 0;
    for (int i = 0; i <= 1000; i++)
    {
        maximum = max(maximum, dp[i] - C * i * i);
    }
    fout << maximum << endl;
    // system("pause");
}