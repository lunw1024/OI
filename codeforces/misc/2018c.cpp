#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int dfs(int u, int prev, int d, vi& cnt, vector<vi>& G) {
    int depth = d;
    for (int v : G[u]) {
        if (v == prev) {
            continue;
        }
        depth = max(depth, dfs(v, u, d + 1, cnt, G));
    }
    cnt[d] += 1;
    cnt[depth + 1] -= 1;
    return depth;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<vi> G(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vi cnt(n + 1);
        int d = dfs(1, 1, 0, cnt, G);
        int ans = n;
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
            ans = min(ans, n - cnt[i]);
        }
        cout << ans << endl;
    }
}

