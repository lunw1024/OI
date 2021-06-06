#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = int(1e6);
int N;

int main() {
    int T;
    cin >> T;
    vector<int> dp(MAXN + 1, 1);
    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        for (int j = 2; (i + 1) * j <= MAXN; j++) {
            dp[(i + 1) * j] = max(dp[(i+1)*j], dp[i] + 1);
        }
    }

    for (int t = 1; t <= T; t++) {
        cin >> N;
        int ans = 0;
        for (int i = 3; i <= N; i++) {
            if (N % i == 0) {
                ans = max(ans, dp[N / i - 1] + 1);
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}