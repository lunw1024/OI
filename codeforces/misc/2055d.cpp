#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int n;
        ll k, l;
        cin >> n >> k >> l;
        k *= 2;
        l *= 2;
        ll t = 0, p = 0;
        ll ans = ll(4e9);
        for (int i = 0; i < n; i++) {
            // cerr << p << ", " << t << endl;
            ll x;
            cin >> x;
            x *= 2;
            if (i == 0) {
                t += x - 0;
                p = k;
                continue;
            }
            if (p >= l) {
                ans = min(ans, t);
            } else {
                ans = min(ans, t + l - p);
            }
            // get as close to p as possible
            if (abs(p - x) <= t) {
                p += k;
            } else if (x + t < p) {
                p = x + t + k;
            } else {
                assert((x - t - p) % 2 == 0);
                int oldp = p;
                p = p + (x - t - p) / 2 + k; 
                t += (x - t - oldp) / 2;
            }
        }
        // cout << p << ", " << t << endl;
        if (p >= l) {
            ans = min(ans, t);
        } else {
            ans = min(ans, t + l - p);
        }
        cout << ans << endl;
    }
}

