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
    vector<pii> q(T);
    vector<ll> ans(T);
    for (int t = 0; t < T; t++) {
        cin >> q[t].first;
        q[t].second = t;
    }
    sort(q.begin(), q.end());
    // precompute
    vector<vector<ll>> dp(1500, vector<ll>(1500));
    ll cnt = 1;
    int p = 0;
    for (int i = 2; i < 1500; i++) {
        // cerr << i << endl;
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] - dp[i - 2][j - 1] + cnt * cnt;
            while (p < T && cnt == q[p].first) {
                ans[q[p].second] = dp[i][j];
                p++;
            }
            cnt++;
        }
    }
    for (int t = 0; t < T; t++) {
        cout << ans[t] << endl;
    }
}

