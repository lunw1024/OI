#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr ll INF = ll(1e18);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, s;
        cin >> n >> s;
        vector<ll> a(n + 1);
        vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        dp[0][0] = 0;
        dp[0][1] = 0;
        ll l = a[0], r = a[0];
        for (int i = 1; i < n - 1; i++) {
            ll nl, nr;
            if (a[i] >= s) {
                nl = a[i] - s;
                nr = s;
            } else {
                nl = 0;
                nr = a[i];
            }
            if (nl > nr) {
                swap(nl, nr);
            }
            dp[i][0] = min(dp[i - 1][0] + l * nr, dp[i - 1][1] + r * nr);
            dp[i][1] = min(dp[i - 1][0] + l * nl, dp[i - 1][1] + r * nl);
            l = nl;
            r = nr;
        }
        ll ans = min(dp[n - 2][0] + l * a[n - 1], dp[n - 2][1] + r * a[n - 1]);
        cout << ans << endl;

    }
}

