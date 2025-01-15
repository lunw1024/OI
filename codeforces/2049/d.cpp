#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const ll INF = ll(1e18);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        ll k;
        cin >> n >> m >> k;
        vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        // cout << "== case " << t << " ==" << endl;
        vector<ll> dp(m + 1, INF);
        dp[1] = 0;
        for (int i = 1; i <= n; i++) {
            vector<ll> ndp(m + 1, INF);
            // make f
            for (int l = 1; l <= m; l++) {
                // init for j = l
                multiset<ll> s;
                vector<ll> pre(m + 1 + m - 1);
                for (int j = 1; j <= 2 * m - 1; j++) {
                    pre[j] = a[i][(j - 1) % m + 1] + pre[j - 1];
                }
                for (int j = l; j <= m + l - 1; j++) {
                    s.insert(pre[j] - pre[j - l] + (j - l) * k);
                }
                ll offset = 0;
                for (int j = l; j <= m; j++) {
                    ll f = *s.begin() - offset;
                    // cerr << "f(" << j << ", " << l << ") = " << f << endl;
                    ndp[j] = min(ndp[j], dp[j - l + 1] + f);
                    offset += k;
                    s.erase(s.find(pre[j] - pre[j - l] + (j - l) * k));
                    s.insert(pre[j] - pre[j - l] + (j - l + m) * k);
                }
            }
            swap(dp, ndp);
            // for (ll x : dp) {
            //     cout << x << " ";
            // }
            // cout << endl;
        }
        cout << dp[m] << endl;
    }
}
