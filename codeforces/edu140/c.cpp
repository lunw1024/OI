// ?000????1111
// ??000??11111
//=00000??11111
// 0: 0/1, 1: same as left, 2: 2 
// dp[i, last same]
// dp[i, j] = sum { dp[i + 1, l <= k < r] + dp[i, k < r] (if l == i and j == i) }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    vector<vector<ll>> dp(N, vector<ll>(N));
    ll ans = 0;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        int l = i, r = N;
        for (int j = i; j < N; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                l = max(l, j);
            } else if (x == 2) {
                r = min(r, j);
            }
        }
        if (r <= l) {
            cout << 0 << endl;
            return 0;
        }
        L[i] = l;
        R[i] = r;
    }

    dp[N - 1][N - 1] = 2;

    for (int i = N - 2; i >= 0; i--) {
        
        if (L[i] == i) { // use diff
            for (int j = i + 1; j < N; j++) {
                dp[i][i] = (dp[i][i] + dp[i + 1][j]) % MOD;
            }
        }
        // use same
        for (int j = L[i]; j < R[i]; j++) {
            dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
        }
    }
    for (int i = 0; i < N; i++) {
        ans += dp[0][i];
    }
    ans %= MOD;
    cout << ans << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "L=" << L[i] << ", R=" << R[i];
    //     cout << endl;
    // }
}
