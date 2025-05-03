#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<vector<bool>> board(n, vector<bool>(2));
        vector<vector<int>> dp(n, vector<int>(2, int(1e9)));
        int l = n, r = 0;
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                char c;
                cin >> c;
                board[i][j] = c == '*';
                if (c == '*') {
                    l = min(l, i);
                    r = max(r, i);
                }
            }
        }
        // init
        dp[l][0] = board[l][1];
        dp[l][1] = board[l][0];
        for (int i = l + 1; i <= r; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + board[i][1 - j] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][1 - j] + 2);
                // cerr << i << ", " << j << ": " << dp[i][j] << endl;
            }
        }
        int ans = min(dp[r][0], dp[r][1]);
        cout << ans << endl;
        
    }
}

