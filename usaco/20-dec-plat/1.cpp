// dp[i, j, k]
// i = total cow or barn processed
// j = cow to match
// k = bool, if there is already a cow not added
// for a cow:
//     for j:
//         dp[i, j, 0] = dp[i - 1, j - 1, 0] (must pick)
//         dp[i, j, 1] = dp[i - 1, j, 0] (not pick, is smallest) + dp[i - 1, j, 1] (not pick, not smallest) + dp[i - 1, j - 1, 1] (pick)
// for a barn:
//     for j:
//         dp[i, j, 0] = dp[i - 1, j + 1, 0] * (j + 1) (match with 1 of j+1 cows) + dp[i - 1, j, 0] (not match)
//         dp[i, j, 1] = dp[i - 1, j + 1, 1] * (j + 1) (must match)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;
int N;
vector<int> S, T;
vector<bool> events;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        S.push_back(s);
    }
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        T.push_back(t);
    }
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    for (int i = 0, j = 0; i < N && j < N;) {
        if (i < N && S[i] <= T[j]) {
            events.push_back(false);
            i++;
        } else if (j < N && S[i] > T[j]) {
            events.push_back(true);
            j++;
        }
    }
    vector<vector<int>> dp(N + 1, vector<int>(2)), ndp(N + 1, vector<int>(2));
    dp[0][0] = 1;
    for (bool e : events) {
        // clear
        for (int i = 0; i <= N; i++)
            ndp[i][0] = 0, ndp[i][1] = 0;
        if (!e) { // cow
            for (int i = 1; i <= N; i++) {
                ndp[i][0] += dp[i - 1][0];
                ndp[i][0] -= ndp[i][0] >= MOD ? MOD : 0;
                ndp[i][1] += dp[i][0];
                ndp[i][1] -= ndp[i][1] >= MOD ? MOD : 0;
                ndp[i][1] += dp[i][1];
                ndp[i][1] -= ndp[i][1] >= MOD ? MOD : 0;
                ndp[i][1] += dp[i - 1][1];
                ndp[i][1] -= ndp[i][1] >= MOD ? MOD : 0;
            }
            ndp[0][1] += dp[0][0];
            ndp[0][1] -= ndp[0][1] >= MOD ? MOD : 0;
            ndp[0][1] += dp[0][1];
            ndp[0][1] -= ndp[0][1] >= MOD ? MOD : 0;
        } else {
            for (int i = 0; i < N; i++) {
                ndp[i][0] += ll(i + 1) * dp[i + 1][0] % MOD;
                ndp[i][0] -= ndp[i][0] >= MOD ? MOD : 0;
                ndp[i][0] += dp[i][0];
                ndp[i][0] -= ndp[i][0] >= MOD ? MOD : 0;
                ndp[i][1] += ll(i + 1) * dp[i + 1][1] % MOD;
                ndp[i][1] -= ndp[i][1] >= MOD ? MOD : 0;
            }
            ndp[N][0] += dp[N][0];
            ndp[N][0] -= ndp[N][0] >= MOD ? MOD : 0;
        }
        swap(dp, ndp);
        // for (int i = 0; i <= N; i++) {
        //     cout << dp[i][0] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i <= N; i++) {
        //     cout << dp[i][1] << " ";
        // }
        // cout << endl << endl;
    }
    cout << (dp[0][0] + dp[0][1]) % MOD << endl;
}