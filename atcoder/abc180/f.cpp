#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;

int N, M, L;

mint solve(int l) {
    vector<vector<mint>> C(N + 1, vector<mint>(N + 1));
    C[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    vector<mint> path(N + 1), cycle(N + 1);
    path[1] = 1, path[2] = 1;
    for (int i = 3; i <= N; i++) {
        path[i] = path[i - 1] * i;
    }
    for (int i = 2; i <= N; i++) {
        cycle[i] = path[i - 1];
    }

    vector<vector<mint>> dp(N + 1, vector<mint>(M + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= min(i, M); j++) {
            dp[i][j] += dp[i - 1][j];
            // k-path
            for (int k = 2; k <= min(min(i, j + 1), l); k++) {
                dp[i][j] += dp[i - k][j - k + 1] * C[N - (i - k) - 1][k - 1] * path[k];
            }
            // k-cycle
            for (int k = 2; k <= min(min(i, j), l); k++) {
                dp[i][j] += dp[i - k][j - k] * C[N - (i - k) - 1][k - 1] * cycle[k];
            }
        }
    }
    return dp[N][M];
}

int main() {
    cin >> N >> M >> L;
    cout << (solve(L) - solve(L - 1)).val() << endl;
}