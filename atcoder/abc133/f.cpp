#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

struct Edge
{
    int to, c;
    ll d;
    Edge(int to, int c, ll d)
    {
        this->to = to;
        this->c = c;
        this->d = d;
    }
};


const int MAXN = 1e5 + 1;
int N, Q, parent[MAXN][17], depth[MAXN] = {0}, dfn[MAXN] = {0};
ll dist[MAXN] = {0};
vector<Edge> edges[(int)1e5 + 1];
vector<pair<int, ll>> euler_order; // (color, d)
vector<pair<int, pair<ll, ll>>> pre[100001]; // (idx, (numPrefix, distPrefix))

inline int sign(int x)
{
    return x >= 0 ? 1 : -1;
}

void dfs(int u, int prev, int deep, ll dis)
{
    parent[u][0] = prev;
    depth[u] = deep;
    dist[u] = dis;
    dfn[u] = euler_order.size();

    for (Edge e : edges[u])
    {
        if (e.to != prev)
        {
            euler_order.push_back(make_pair(e.c, e.d));
            dfs(e.to, u, deep + 1, dis + e.d);
            euler_order.push_back(make_pair(e.c, -e.d));
        }
    }
}

void preprocess()
{
    dfs(1, 1, 0, 0);

    // lca
    for (int k = 1; k <= 16; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
        }
    }

    // euler order
    for (int i = 1; i <= N; i++)
    {
        pre[i].push_back(make_pair(0, make_pair(0, 0)));
    }
    for (int i = 0; i < euler_order.size(); i++)
    {
        int c = euler_order[i].first;
        ll d = euler_order[i].second;
        pre[c].push_back(make_pair(i + 1, make_pair(pre[c].back().second.first + sign(d), pre[c].back().second.second + d)));
    }
}

int get_lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    
    for (int k = 16; k >= 0; k--)
    {
        if (depth[parent[a][k]] >= depth[b])
            a = parent[a][k];
    }

    for (int k = 16; k >= 0; k--)
    {
        if (parent[a][k] != parent[b][k])
            a = parent[a][k], b = parent[b][k];
    }

    if (a != b)
        a = parent[a][0], b = parent[b][0];
    
    return a;
}

ll get_num(int x, int c)
{
    auto target = make_pair(dfn[x], make_pair((ll)1e18, (ll)1e18));
    auto it = lower_bound(pre[c].begin(), pre[c].end(), target);
    it--;
    // cout << x << " " << c << " " << it - pre[c].begin() << " " << (*it).first << " " << (*it).second.first << endl;
    return (*it).second.first;
}

ll get_sum(int x, int c)
{
    auto target = make_pair(dfn[x], make_pair((ll)1e18, (ll)1e18));
    auto it = lower_bound(pre[c].begin(), pre[c].end(), target);
    it--;
    return (*it).second.second;
}

int main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N - 1; i++)
    {
        int a, b, c;
        ll d;
        cin >> a >> b >> c >> d;
        edges[a].push_back(Edge(b, c, d));
        edges[b].push_back(Edge(a, c, d));
    }

    preprocess();

    for (int i = 1; i <= Q; i++)
    {
        int c, a, b;
        ll d;
        cin >> c >> d >> a >> b;
        int lca = get_lca(a, b);
        ll ans = dist[a] + dist[b] - 2 * dist[lca];
        ans += (get_num(a, c) + get_num(b, c) - 2 * get_num(lca, c)) * d - (get_sum(a, c) + get_sum(b, c) - 2 * get_sum(lca, c));
        cout << ans << endl;
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     // for (auto ele : pre[i])
    //     // {
    //     //     cout << ele.first << " " << ele.second.first << " " << ele.second.second << endl;
    //     // }
    //     // cout << dfn[i] << endl;
    // }
    // system("pause"); 
}
