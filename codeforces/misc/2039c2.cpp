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
        ll x, m;
        cin >> x >> m;
        ll ans = 0;
        // div by x
        ans += (m + x + 1) / x; // k = 0, 2, 3, 4...
        while ((x ^ (ans * x)) > m) {
            ans--;
        }
        if ((x ^ ((ans - 1) * x)) > m) {
            ans--;
        }
        // cerr << "ans = " << ans << endl;
        // div by y only
        for (int y = 1; y <= min(m, x); y++) {
            for (int ky = y * 2; ky - y <= x; ky += y) {
                if ((x ^ y) == ky && ky % x != 0) {
                    ans++;
                    // cerr << "found " << y << " ky = " << ky << endl;
                }
            }
        }
        cout << ans << endl;
    }
}

