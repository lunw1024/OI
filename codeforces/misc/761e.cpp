#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<int>;

const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool dfs(vector<vector<int>>& G, vector<pii>& ans, vector<bool>& vis, int u, int order, ll x, ll y, int dir) {
    ans[u] = {x, y};
    vis[u] = true;
    // cerr << u << " = (" << x << ", " << y << ")" << endl;
    if (G[u].size() > 4) {
        return false;
    }
    int d = 0;
    for (int v : G[u]) {
        if (vis[v]) {
            continue;
        }
        if (d != -1 && d != dir && d % 2 == dir % 2) {
            d++;
        }
        bool ok = dfs(G, ans, vis, v, order - 1, x + dx[d] * (1ll << order), y + dy[d] * (1ll << order), d);
        if (!ok) {
            return false;
        }
        d++;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> G(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<pii> ans(n);
    vector<bool> vis(n);
    bool ok = dfs(G, ans, vis, 0, 32, 0, 0, -1);
    if (!ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto [x, y] : ans) {
            cout << x << " " << y << endl;
        }
    }
}

