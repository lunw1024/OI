#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = ll(1e18);

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        vector<vector<ll>> dp(n + 1, vector<ll>(k+1, INF));
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        fill(dp[0].begin(), dp[0].end(), 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                ll mn = INF;
                for (int d = 0; d <= j && d < i; d++) {
                    // use d tokens
                    mn = min(mn, a[i - d]);
                    // cout << "min = " << mn << endl;
                    dp[i][j] = min(dp[i][j], dp[i - 1 - d][j - d] + mn * (d + 1));
                }
            }
        }
        ll ans = INF;
        for (int i = 0; i <= k; i++) {
            ans = min(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
}
