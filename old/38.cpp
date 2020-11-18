#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 50001, MAXM = 50001, MAXK = 16;
int N, M;
vector<pair<int, int>> edges[MAXN]; // (id, w)
bool isDeep1[MAXN] = {0};
int father[MAXN][MAXK], troop[MAXM], depth[MAXN];
ll dist[MAXN][MAXK];
bool visited[MAXN] = {0}, occupied[MAXN] = {0};

void preprocess_dfs(int u, int dep)
{
    visited[u] = true;
    depth[u] = dep;
    for (pair<int, int> v : edges[u])
    {
        if (!visited[v.first])
        {
            father[v.first][0] = u;
            dist[v.first][0] = v.second;
            preprocess_dfs(v.first, dep + 1);
        }
    }
}

void preprocess()
{
    fill(visited, visited + MAXN, false);
    preprocess_dfs(1, 1);

    // dp
    father[1][0] = 1;
    dist[1][0] = 0;
    for (int k = 1; k < MAXK; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            father[i][k] = father[father[i][k - 1]][k - 1];
            dist[i][k] = dist[i][k - 1] + dist[father[i][k - 1]][k - 1];
        }
    }

}

bool dfs(int u)
{
    bool isleaf = true;
    if (occupied[u])
    {
        return true;
    }

    for (pair<int, int> temp : edges[u])
    {
        int v = temp.first;
        if (depth[v] < depth[u])
        {
            continue;
        }

        isleaf = false;
        if (!dfs(v))
        {
            return false;
        }
    }
    return true;
}

vector<pair<ll, int>> settledTroops; // (leftTime, pos)
bool need[MAXN] = {0};
bool check(ll maxTime)
{
    fill(occupied, occupied + MAXN, false);
    fill(need, need + MAXN, false);

    // move troop
    for (int i = 1; i <= M; i++)
    {
        int p = troop[i];
        ll time = 0;
        for (int k = MAXK - 1; k >= 0; k--)
        {
            if (father[p][k] > 1 && time + dist[p][k] <= maxTime)
            {
                time += dist[p][k];
                p = father[p][k];
            }
        }

        if (father[p][0] == 1 && time + dist[p][0] <= maxTime)
        {
            settledTroops.push_back(make_pair(maxTime - time - dist[p][0], p));
        }
        else
        {
            occupied[p] = true;
        }
    }

    // check whether is already covered
    for (pair<int, int> v : edges[1])
    {
        if (!dfs(v.first))
        {
            need[v.first] = true;
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> troop[i];
    }

    ll l = 0, r = 1e18;

}