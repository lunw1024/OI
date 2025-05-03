#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void dfs(int u, vector<vi>& G, vector<bool>& vis, vi& ans) {
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v])
            dfs(v, G, vis, ans);
    }
    ans.push_back(u);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, st, en;
        cin >> n >> st >> en;
        vector<vi> G(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<bool> vis(n + 1);
        vi ans;
        dfs(en, G, vis, ans);
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}

