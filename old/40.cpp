#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 200000 + 1;
int N, M, A, B;
vector<pair<int, ll> > edges[MAXN]; // (u, w)
bool visited[MAXN] = {0};
ll dist[2][MAXN];

// return farthest leaf id and dis
pair<int, ll> dfs(int u, ll depth, int special)
{
    if (special != -1)
    {
        dist[special][u] = depth;
    }

    visited[u] = true;
    pair<int, ll> out = make_pair(u, depth);
    for (pair<int, ll> temp : edges[u])
    {
        int v = temp.first;
        ll w = temp.second;
        if (!visited[v])
        {
            pair<int, ll> result = dfs(v, depth + w, special);
            if (out.second < result.second)
            {
                out = result;
            }
        }
    }
    return out;
}


int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges[a].push_back(make_pair(b, w));
        edges[b].push_back(make_pair(a, w));

    }

    fill(visited + 1, visited + 1 + N, false);
    pair<int, ll> D1 = dfs(1, 0, -1);
    fill(visited + 1, visited + 1 + N, false);
    pair<int, ll> D2 = dfs(D1.first, 0, -1);

    A = D1.first;
    B = D2.first;
    ll diameter = D2.second;

    fill(visited + 1, visited + 1 + N, false);
    fill(&dist[0][0], &dist[1][N + 1], (ll)1e10);
    dfs(A, 0, 0);
    fill(visited + 1, visited + 1 + N, false);
    dfs(B, 0, 1);

    ll maximum = 0;
    for (int i = 1; i <= N; i++)
    {
        maximum = max(maximum, min(dist[0][i], dist[1][i]));
    }

    cout << diameter + maximum << endl;
    // system("pause");
}
