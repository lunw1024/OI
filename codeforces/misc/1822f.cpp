#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using pii = pair<int, int>;
using vi = vector<int>;

pii dfs(int u, int prev, int depth, vi& d, vi& d1, vi& d2, vector<vector<int>>& G) {
    d[u] = depth;
    for (int v : G[u]) {
        if (v == prev) {
            continue;
        }
        auto [h1, h2] = dfs(v, u, depth + 1, d, d1, d2, G);
        for (int h : {h1}) {
            d2[u] = max(d2[u], h + 1);
            if (d2[u] > d1[u]) {
                swap(d2[u], d1[u]);
            }
        }
    }
    return {d1[u], d2[u]};
}

void dfs2(int u, int prev, vi& up, vi& d1, vi& d2, vector<vector<int>>& G) {
    if (u != prev) {
        up[u] = max(1 + up[prev], (d1[prev] == d1[u] + 1 ? 1 + d2[prev] : 1 + d1[prev]));
    } else {
        up[u] = 0;
    }
    for (int v : G[u]) {
        if (v == prev) {
            continue;
        }
        dfs2(v, u, up, d1, d2, G);
    }
}

void solve() {
    int n;
    i64 k, c;
    cin >> n >> k >> c;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vi d(n + 1), d1(n + 1), d2(n + 1), up(n + 1);
    dfs(1, 1, 0, d, d1, d2, G);
    dfs2(1, 1, up, d1, d2, G);
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 profit = i64(max(d1[i], up[i])) * k - c * d[i];
        // cerr << "d=" << d[i] << ", d1=" << d1[i] << ", d2=" << d2[i] << ", up=" << up[i] << endl;
        // cerr << "profit at " << i << " = " << profit << endl;
        ans = max(ans, profit);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

