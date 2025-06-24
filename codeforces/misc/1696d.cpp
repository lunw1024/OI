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
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        int p = 0, nxt = 0;
        int ans = 0;
        int dir = (a[1] - a[0]) / abs(a[1] - a[0]);
        for (int i = 1; i < n; i++) {
            if (a[i] * dir > a[nxt] * dir) {
                nxt = i;
            }
            if (a[i] * dir < a[p] * dir) {
                ans++;
                // cerr << "going from " << p << " -> " << nxt << "new dir = " << -dir << endl;
                p = nxt;
                nxt = i;
                dir = -dir;
            }
        }
        vector<vector<bool>> flags(n, vector<bool>(2));
        int l = a[n - 1], r = a[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            l = min(a[i], l);
            r = max(a[i], r);
            if (a[i] == l) {
                flags[i][0] = true;
            }
            if (a[i] == r) {
                flags[i][1] = true;
            }
        }
        for (int i = p + 1; i < n; i++) {
            if (flags[i][(dir + 1) / 2]) {
                ans += 1;
                // cerr << "going to " << i << "new dir = " << -dir << endl;
                dir = -dir;
            }
        }
        cout << ans << endl;
        
    }
}

