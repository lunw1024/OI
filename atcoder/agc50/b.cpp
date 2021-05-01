// a legal sequence can be divided into segments such that 
// {x1, ..., xn | xi%3 is consecutive}
// dp[i, m, l] = max value for first i characters, last '1''s position % 3 == m, length % 3 == l
// dp[i, m, l] -> dp[i + 1, m, l]
// dp[i, m, l] -> dp[i + 1, (m + 1) % 3, (l + 1) % 3] if i == m (mod 3)
// dp[i, m, l] -> dp[i + 1, (i + 1) % 3, 1] if l % 3 == 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = int(1e9);
int N;
vector<int> arr;

inline void ckmax(int& a, int b) {
    a = max(a, b);
}

int main() {
    cin >> N;
    arr.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(3, vector<int>(3, -INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int m = 0; m < 3; m++) {
            for (int l = 0; l < 3; l++) {
                ckmax(dp[i + 1][m][l], dp[i][m][l]);
                if (i % 3 == m % 3)
                    ckmax(dp[i + 1][(m+1)%3][(l+1)%3], dp[i][m][l] + arr[i + 1]);
                if (l % 3 == 0)
                    ckmax(dp[i + 1][(i+1)%3][1], dp[i][m][l] + arr[i + 1]);
            }
        }
    }

    int ans = -INF;
    for (int i = 0; i < 3; i++) {
        ckmax(ans, dp[N][i][0]);
    }
    cout << ans << endl;
}
