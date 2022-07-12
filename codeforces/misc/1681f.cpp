#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int N, logN, head;
vector<vector<Edge>> edges;
vector<vector<int>> G;
vector<int> sz, dfn, depth, group;
vector<vector<int>> fa;
vector<vector<int>> pts;

void init(int u, int prev) {
    sz[u] = 1;
    dfn[u] = head++;
    fa[u][0] = prev;
    for (Edge e: edges[u]) {
        int v = e.v;
        if (v == prev)
            continue;
        depth[v] = depth[u] + 1;
        init(v, u);
        sz[u] += sz[v];
        group[v] = e.w;
    }
}

bool comp(int a, int b) {
    return dfn[a] < dfn[b];
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    for (int i = logN - 1; i >= 0; i--) {
        if (depth[fa[x][i] >= depth[y]]) {
            x = fa[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = logN - 1; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

vector<vector<ll>> dp;
ll dfs(int u, int w) {
    // cerr << "dfs(" << u << ")" << endl;
    ll res = 0;
    for (int v : G[u]) {
        res += dfs(v, w);
    }
    dp[u][0] = sz[u];
    dp[u][1] = 0;
    for (int v : G[u]) {
        dp[u][0] -= sz[v];
    }
    for (int v : G[u]) {
        if (group[v] == w) {
            dp[u][1] += dp[v][0];
            res += dp[v][0] * dp[u][0];
        } else {
            res += dp[u][1] * dp[v][0];
            res += dp[u][0] * dp[v][1];
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
    }
    return res;
}

int main() {
    cin >> N;
    logN = int(log2(N)) + 1;
    G.resize(N);
    edges.resize(N);
    depth.resize(N);
    group.resize(N);
    sz.resize(N);
    dfn.resize(N);
    fa.resize(N, vector<int>(logN));
    pts.resize(N);
    dp.resize(N, vector<ll>(2));

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--, w--;
        edges[u].push_back(Edge(u, v, w));
        edges[v].push_back(Edge(v, u, w));
        pts[w].push_back(u);
        pts[w].push_back(v);
    }


    init(0, 0);

    for (int i = 1; i < logN; i++) {
        for (int u = 0; u < N; u++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
    }
    // cerr << "point 1" << endl;
    // make virtual tree
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        sort(pts[i].begin(), pts[i].end(), comp);
        pts[i].resize(unique(pts[i].begin(), pts[i].end()) - pts[i].begin());
        vector<int> s;
        G[0].clear();
        s.push_back(0);
        for (int u: pts[i]) {
            if (u == 0)
                continue;
            int l = lca(u, s.back());
            if (l != s.back()) {
                while (dfn[l] < dfn[s.back()]) {
                    G[s[s.size() - 2]].push_back(s.back());
                    // cerr << s[s.size() - 2] << " -> " << s.back() << endl;
                    s.pop_back();
                }
            }
            G[u].clear();
            s.push_back(u);
        }
        while (s.size() >= 2) {
            G[s[s.size() - 2]].push_back(s.back());
            // cerr << s[s.size() - 2] << " -> " << s.back() << endl;
            s.pop_back();
        }
        
        // dp on virtual tree
        // dp[N, 2]
        ans += dfs(0, i);
        
    }
    cout << ans << endl;


}
