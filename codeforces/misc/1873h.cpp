#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int dfs(int u, int prev, vector<bool>& vis, vector<vector<int>>& G) {
    vis[u] = true;
    for (int v : G[u]) {
        if (vis[v]) {
            if (v != prev) {
                return v;
            }
            continue;
        }
        int res = dfs(v, u, vis, G);
        if (res != 0) {
            return res;
        }
    }
    return 0;
}

int bfs(int s, int t, vector<vector<int>>& G) {
    queue<int> q;
    int n = G.size() - 1;
    q.push(s);
    vector<int> dist(n + 1, int(1e9));
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dist[v] == int(1e9)) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        vector<bool> vis(n + 1);
        int entry = dfs(b, b, vis, G);
        int d1 = bfs(a, entry, G), d2 = bfs(b, entry, G);
        cout << (d1 <= d2 ? "NO": "YES") << endl;
    }
}

