#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<vi> G(n + 1);
        vi d(n + 1);
        int maxd = 0;
        vector<vi> D(n + 1);
        vector<ll> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            int p;
            cin >> p;
            G[p].push_back(i);
            d[i] = d[p] + 1;
            maxd = max(maxd, d[i]);
            D[d[i]].push_back(i);
        }
        for (int i = maxd; i >= 1; i--) {
            ll s = 1;
            for (int v : D[i + 1]) {
                s = (s + dp[v]) % MOD;
            }
            for (int v : D[i]) {
                dp[v] = s;
                for (int u : G[v]) {
                    dp[v] = (dp[v] - dp[u] + MOD) % MOD;
                }
                // cerr << "dp[" << v << "] = " << dp[v] << endl;
            }
        }
        ll ans = 1;
        for (int v : D[1]) {
            ans = (ans + dp[v]) % MOD;
        }
        cout << ans << endl;
    }
}

