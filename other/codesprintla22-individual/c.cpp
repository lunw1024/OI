#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, L;
    double p;
    cin >> N >> L >> p;

    vector<double> powp(N + 1);
    powp[0] = 1;
    for (int i = 1; i <= N; i++) {
        powp[i] = powp[i - 1] * p;
    }
    powp[1] = 0;

    vector<vector<double>> dp(N + 1, vector<double>(L + 1));
    dp[N][L] = 1;
    for (int n = N; n >= 1; n--) {
        for (int l = L; l >= 0; l--) {
            double push = n < N && l > 0 ? dp[n + 1][l] * powp[n + 1] : 0;
            double success = l < L ? dp[n][l + 1] * 0.5 * (1 - powp[n]) : 0;
            double fail = n < N && l < L ? dp[n + 1][l + 1] * 0.5 * (1 - powp[n + 1]) : 0;
            dp[n][l] += push + success + fail;
            // cout << "[" << n << ", " << l << "] = " << push << ", " << success << ", " << fail << " = " << dp[n][l] << endl;
        }
    }
    double ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[i][0];
    }
    cout << ans << endl;
}
