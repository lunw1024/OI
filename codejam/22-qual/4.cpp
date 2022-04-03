#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int N;
vector<vector<int>> edges;
vector<ll> F;
const ll INF = ll(1e18);

pair<ll, ll> dfs(int u) {
    ll ans = 0, x = INF;
    for (int v : edges[u]) {
        pair<ll, ll> res = dfs(v);
        ll s = res.first, m = res.second;
        ans += s;
        x = min(x, m);
    }
    x = x == INF ? 0 : x;
    if (F[u] > x) {
        ans += F[u] - x;
        x = F[u];
    }
    // cerr << "dfs(" << u << ") = " << "(" << ans << ", " << x << ")" << endl;
    return make_pair(ans, x);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        edges.clear();
        edges.resize(N + 1);
        F.clear();
        F.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> F[i];
        }
        for (int i = 1; i <= N; i++) {
            int p;
            cin >> p;
            edges[p].push_back(i);
        }
        ll ans = dfs(0).first;
        cout << "Case #" << t << ": " << ans << endl;
    }
}
