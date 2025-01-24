#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    // adj matrix
    vector<vi> f(n, vi(n, 1));
    vi l(n), r(n);
    for (int qq = 0; qq < q; qq++) {
        // maintain l[snake], r[snake]
        // f(i, j) <- r[i] - l[j]
        int x;
        char move;
        cin >> x >> move;
        x--;
        if (move == '+') {
            r[x] += 1;
        } else {
            l[x] += 1;
        }
        for (int i = 0; i < n; i++) {
            f[i][x] = max(f[i][x], r[i] - l[x] + 1);
            f[x][i] = max(f[x][i], r[x] - l[i] + 1);
        }
    }
    // dp
    vector<vi> dp(1 << n, vi(n, static_cast<int>(1e9)));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            // i is last snake
            for (int j = 0; j < n; j++) {
                if ((1 << j) & mask) {
                    continue; // snake alr in mask
                }
                int newmask = mask | (1 << j);
                int result = dp[mask][i] + f[i][j];
                dp[newmask][j] = min(dp[newmask][j], result);
            }
        }
    }
    // gather ans
    int final_mask = (1 << n) - 1;
    int ans = static_cast<int>(1e9);
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[final_mask][i] + r[i]);
    }
    cout << ans << endl;
}

