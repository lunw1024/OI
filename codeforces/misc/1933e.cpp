#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    vector<i64> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, u;
        cin >> s >> u;
        auto it = upper_bound(pre.begin() + s, pre.end(), u + pre[s - 1]);
        i64 ans = -int(1e9);
        if (it != pre.end()) {
            // check r + 1
            i64 m = *it - pre[s - 1];
            ans = max(ans, (2 * u + 1 - m) * m / 2);
        }
        // cerr << "checking r=" << (it - pre.begin() - 1) << endl;
        // check r
        i64 m = *(it - 1) - pre[s - 1];
        i64 ans1 = (2 * u + 1 - m) * m / 2;
        // cerr << "ans=" << ans << ", ans1=" << ans1 << endl;
        int idx = ans1 >= ans ? it - pre.begin() - 1 : it - pre.begin();
        i64 val = pre[idx];
        int idx_best = lower_bound(pre.begin() + s, pre.end(), val) - pre.begin();
        cout << idx_best << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

