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
        ll x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vi v;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                v.push_back(i);
            }
        }
        if (v.size() == 0) {
            cout << 0 << endl;
            continue;
        }
        if (v.size() % 2 != 0) {
            cout << -1 << endl;
            continue;
        }
        if (x >= y) {
            if (v.size() == 2) {
                cout << (v[1] - v[0] == 1 ? min(2 * y, x) : min(y, x * (v[1] - v[0]))) << endl;
            } else {
                cout << (y * v.size() / 2) << endl;
            }
            continue;
        }
        vector<ll> dp(v.size());
        dp[0] = 0;
        if (v[1] - v[0] == 1) {
            dp[1] = min(2 * y, x);
        } else {
            dp[1] = min(y, x * (v[1] - v[0]));
        }
        for (int i = 2; i < v.size(); i++) {
            if (i % 2 == 0) {
                // odd
                dp[i] = min(dp[i - 1], dp[i - 2] + (v[i] - v[i - 1]) * x);
            } else {
                // even
                dp[i] = min(dp[i - 1] + y, dp[i - 2] + (v[i] - v[i - 1]) * x);
            }
        }
        cout << dp[v.size() - 1] << endl;
    }
}

