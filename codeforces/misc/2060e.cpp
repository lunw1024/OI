#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void dfs(int leader, int u, vi& leaders, vector<vi>& G) {
    if (leaders[u] != 0) {
        return;
    }
    leaders[u] = leader;
    for (int v : G[u]) {
        dfs(leader, v, leaders, G);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        vector<vector<int>> F(n + 1), G(n + 1);
        vector<pii> edges;
        for (int i = 0; i < m1; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        for (int i = 0; i < m2; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> leaders(n + 1);
        for (int i = 1; i <= n; i++) {
            dfs(i, i, leaders, G);
            // cerr << "l[" << i << "] = " << leaders[i] << endl;
        }
        int ans = 0;
        for (pii e : edges) {
            if (leaders[e.first] != leaders[e.second]) {
                ans++;
            } else {
                F[e.first].push_back(e.second);
                F[e.second].push_back(e.first);
            }
        }
        // cout << ans << "edges deleted" << endl;
        vector<int> grp(n + 1);
        for (int i = 1; i <= n; i++) {
            dfs(i, i, grp, F);
        }
        sort(grp.begin() + 1, grp.end());
        sort(leaders.begin() + 1, leaders.end());
        int x = std::unique(grp.begin() + 1, grp.end()) - grp.begin();
        int y = std::unique(leaders.begin() + 1, leaders.end()) - leaders.begin();
        // cerr << "x = " << x << " y = " << y << endl;
        ans += x - y;
        cout << ans << endl;
    }
}

