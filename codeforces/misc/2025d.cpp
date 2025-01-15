#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1), diff(m + 1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        if (r == 0) {
            int sum = 0;
            for (int j = 0; j <= cnt; j++) {
                sum += diff[j];
                dp[j] += sum;
            }
            fill(diff.begin(), diff.end(), 0);
            for (int j = cnt + 1; j > 0; j--) {
                dp[j] = max(dp[j - 1], dp[j]);
            }
            cnt++;
        } else if (r > 0) {
            diff[r]++;
        } else {
            if (-r > cnt) {
                continue;
            }
            diff[0]++;
            diff[cnt + r + 1]--;
        }
        // cerr << cnt << ": ";
        // for (int j = 0; j <= m; j++) {
        //     cerr << dp[j] << " ";
        // }
        // cerr << endl;
    }
    int sum = 0;
    for (int j = 0; j <= cnt; j++) {
        sum += diff[j];
        dp[j] += sum;
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}
