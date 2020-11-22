#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cassert>
using namespace std;
typedef long long ll;

const int MAXN = 100001;
int N;
ll ans = 0;
vector<int> edges[2][MAXN];
bool vis[2][MAXN] = {0};
ll r = 0, c = 0, edgeCnt = 0;

void dfs(bool group, int u)
{
    vis[group][u] = true;
    if (group)
        r++;
    else
        c++;
    if (group == false)
        edgeCnt += edges[group][u].size();

    for (int i = 0; i < edges[group][u].size(); i++)
    {
        int v = edges[group][u][i];
        if (!vis[!group][v])
        {
            dfs(!group, v);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[0][x].push_back(y);
        edges[1][y].push_back(x);
    }

    for (int i = 1; i <= 100000; i++)
    {
        if (!vis[0][i])
        {
            r = 0, c = 0, edgeCnt = 0;
            dfs(false, i);
            // cout << i << " " << edgeCnt << endl;
            ans += 1ll * r * c - edgeCnt;
        }
    }
    cout << ans << endl;
    // system("pause");
}