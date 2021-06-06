// (i+j+k, i, j)
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;

ll N, K;

int main() {
    cin >> N >> K;
    vector<vector<ll>> dp(4, vector<ll>(3 * N + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3 * N; j++) {
            dp[i - 1][j] += dp[i - 1][j - 1];
            dp[i][j] = dp[i - 1][j - 1] - (j - N <= 0 ? 0ll : dp[i - 1][j - N - 1]);
        }
    }
    ll s = 0;
    while (dp[3][s] < K) {
        K -= dp[3][s];
        s++;
    }
    // cerr << "s = " << s << ", K = " << K << endl;
    for (ll i = max(1ll, s - 2 * N); i <= min(s - 2, N); i++) {
        ll x = (s - i - 1) - max(1ll, s - i - N) + 1;
        if (K > x) {
            K -= x;
        } else {
            ll j = max(1ll, s - i - N) + K - 1;
            assert(1 <= i && i <= N);
            assert(1 <= j && j <= N);
            assert(1 <= s - i - j && s - i - j <= N);
            cout << i << " " << j << " " << s - i - j << endl;
            break;
        }
    }
}
