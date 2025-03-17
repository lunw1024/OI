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
        vector<pii> segs;
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            if (i - b >= 1) {
                segs.push_back({i - b, i});
            }
            if (i + b <= n) {
                segs.push_back({i, i + b});
            }
        }
        sort(segs.begin(), segs.end());
        for (pii seg : segs) {
            int l = seg.first, r = seg.second;
            dp[r] = dp[r] || dp[l - 1];
        }
        cout << (dp[n] ? "YES" : "NO") << endl;
    }
}

