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
        int n, x;
        cin >> n >> x;
        vector<ll> a(n);
        ll low = ll(1e9), high = 0;
        ll lowside = ll(1e9), highside = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            low = min(low, a[i]);
            high = max(high, a[i]);
            if (i == 0 || i == n - 1) {
                lowside = min(lowside, a[i]);
                highside = max(highside, a[i]);
            }
            if (i > 0) {
                ans += abs(a[i] - a[i - 1]);
            }
        }
        if (1 < low) {
            ans += min(2 * (low - 1), lowside - 1);
        }
        // cerr << highside << endl;
        if (high < x) {
            ans += min(2 * (x - high), x - highside);
        }
        cout << ans << endl;
    }
}

