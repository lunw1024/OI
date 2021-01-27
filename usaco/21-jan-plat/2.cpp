#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
int N, M, Q;

int main() {
    cin >> N >> M;
    vector<ll> C(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> C[i];
    bool flag = true;
    for (int i = 3; i <= M; i++) {
        if (C[i - 1] < C[i])
            flag = false;
    }
    cin >> Q;
    if (flag) {
        for (int q = 1; q <= Q; q++) {
            ll x, y;
            cin >> x >> y;
            if (y == 1) {
                cout << C[1] * (x - 1) << endl;
                continue;
            }
            double axis = 1.0 * (C[y] - C[1]) / (2 * y - 2);
            ll k = min(x, max(1ll, ll(round(axis))));
            ll ans = (y - 1) * k * k + (C[1] - C[y]) * k - C[1] + C[y] * x;
            cout << ans << endl;
        }
        return 0;
    }
    
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1)
                continue;
            if (i == 1)
                dp[i][j] = j - 1;
            else if (j == 1)
                dp[i][j] = C[j] * (i - 1);
            else {
                dp[i][j] = min(dp[i - 1][j] + C[j], dp[i][j - 1] + i * i);
            }
        }
    }
    for (int q = 1; q <= Q; q++) {
        int x, y;
        cin >> x >> y;
        cout << dp[x][y] << endl;
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}