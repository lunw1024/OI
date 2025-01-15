#include <iostream>
#include <vector>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;
    vector<vector<bool>> dp(c + 1, vector<bool>(c + 1));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int x = c; x >= 0; x--) {
            for (int y = c; y >= 0; y--) {
                if (x >= t) {
                    dp[x][y] = dp[x][y] || dp[x-t][y];
                    // cerr << x << " " << y << endl;
                }
                if (y >= t) {
                    dp[x][y] = dp[x][y] || dp[x][y - t];
                }
            }
        }
    }
    int a = 0, b = 0, ans = 0;
    for (int x = c; x >= 0; x--) {
        for (int y = x; y >= 0; y--) {
            if (dp[x][y]) {
                // cerr << "hi" << endl;
                if (x + y > ans) {
                    ans = x + y;
                    a = x;
                    b = y;
                } else if (x + y == ans) {
                    if (a - b > x - y) {
                        a = x;
                        b = y;
                    }
                }
            }
        }
    }
    cout << a << " " << b << endl;
}
