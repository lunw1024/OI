#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = int(1e9);
int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    auto dp = vector<vector<vector<int>>>();
    dp.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(n * n + 1, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i * (i - 1); k++) {
                dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k] + (s[i] == '1'));
                dp[i + 1][j][k + j] = min(dp[i + 1][j][k + j], dp[i][j][k] + (s[i] == '0'));
            }
        }
    }
    int m = 0;
    int p = 0;
    for (char c : s) {
        m += c == '0';
    }
    p = m * (n - m);
    // cout << n << " " << m << " " << p << endl;a
    cout << dp[n][m][p / 2] / 2 << endl;
}
