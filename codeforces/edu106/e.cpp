#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;
int N, M;
string x, y;
vector<vector<vector<int>>> dp;

inline int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int main() {
    cin >> x >> y;
    N = x.size(), M = y.size();
    dp.resize(N + 1, vector<vector<int>>(M + 1, vector<int>(2)));
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // start substring
            if (i < N)
                dp[i + 1][j][0] = add(dp[i + 1][j][0], 1);
            if (j < M)
                dp[i][j + 1][1] = add(dp[i][j + 1][1], 1);
            // extend
            if (0 < i && i < N && x[i - 1] != x[i])
                dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][0]);
            if (0 < j && i < N && y[j - 1] != x[i])
                dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][j][1]);
            if (0 < i && j < M && x[i - 1] != y[j])
                dp[i][j + 1][1] = add(dp[i][j + 1][1], dp[i][j][0]);
            if (0 < j && j < M && y[j - 1] != y[j])
                dp[i][j + 1][1] = add(dp[i][j + 1][1], dp[i][j][1]);
            // record sum
            ans = add(ans, dp[i][j][0]);
            ans = add(ans, dp[i][j][1]);
        }
    }
    // remove illegal solutions (one substring is empty)
    // ans -= sum(chaotic substrings of x * (M + 1)) + sum(chaotic substrings of y * (N + 1))
    for (int i = 0; i < N;) {
        int j = i + 1, len = 1;
        while (j < N && x[j - 1] != x[j])
            j++, len++;
        ans = ((ans - ll(len) * (len + 1) / 2 % MOD * (M + 1) % MOD) % MOD + MOD) % MOD;
        i = j;
    }
    for (int i = 0; i < M;) {
        int j = i + 1, len = 1;
        while (j < M && y[j - 1] != y[j])
            j++, len++;
        ans = ((ans - ll(len) * (len + 1) / 2 % MOD * (N + 1) % MOD) % MOD + MOD) % MOD;
        i = j;
    }
    cout << ans << endl;
}