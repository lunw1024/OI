#include <iostream>
#include <vector>
using namespace std;

const int INF = static_cast<int>(1e9);

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> dp(n + 1), m(n + 1), c(n + 1);
    vector<bool> isvisit(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> m[i] >> c[i];        
    }
    vector<int> visits(d);
    for (int i = 0; i < d; i++) {
        int x;
        cin >> x;
        isvisit[x] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= ans; j--) {
            if (dp[j] == INF) {
                break;
            }
            dp[j] += m[i];
            if (j > 0) {
                dp[j] = min(dp[j], max(0, dp[j - 1] + m[i] - c[i]));
            }
        }
        if (isvisit[i]) {
            for (int j = ans; j <= n; j++) {
                if (dp[j] > 0) {
                    dp[j] = INF;
                    ans = j + 1;
                }
            }
        }
        if (ans > i) {
            ans = -1;
            break;
        }        
    }
    cout << ans << endl;
}
