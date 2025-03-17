#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[0] = ll(1e18);
        a[n + 1] = ll(1e18);
        queue<pair<ll, ll>> l, r;
        l.push(make_pair(ll(0), ll(0)));
        r.push(make_pair(ll(0), ll(0)));
        ll h = a[k];
        ll presum = 0, premin = 0;
        for (int i = k - 1; i >= 0; i--) {
            // cerr << "i = " << i << endl;
            presum += a[i];
            l.back().second = max(l.back().second, presum);
            if (presum < premin) {
                l.push(make_pair(presum, presum));
                premin = presum;
            }
        }
        presum = 0;
        premin = 0;
        for (int i = k + 1; i <= n + 1; i++) {
            // cerr << "i = " << i << endl;
            presum += a[i];
            r.back().second = max(r.back().second, presum);
            if (presum < premin) {
                r.push(make_pair(presum, presum));
                premin = presum;
            }
        }

        // solve
        ll hl = 0, hr = 0;
        bool updated = true;
        while (updated) {
            updated = false;
            // cout <<l.size() << endl;
            while (l.front().second - hl <= 0) {
                // cerr << "popping " << l.front().first << ", " << l.front().second << endl;
                l.pop();
            }
            while (r.front().second - hr <= 0) {
                r.pop();
            }
            // cerr << h << ", " << hl << ", " << hr << endl;
            while (!l.empty() && h + hr >= -l.front().first) {
                hl = l.front().second;
                // cerr << "merging " << l.front().first << ", " << l.front().second << endl;
                l.pop();
                updated = true;
            }
            while (!r.empty() && h + hl >= -r.front().first) {
                hr = r.front().second;
                r.pop();
                updated = true;
            }
            if (l.empty() || r.empty()) {
                break;
            }
            // cerr << h << ", " << hl << ", " << hr << endl;
        }
        cout << (l.empty() || r.empty() ? "YES" : "NO") << endl;
    }
}

