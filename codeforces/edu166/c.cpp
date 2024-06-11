#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + m + 1), b(n + m + 1);
        for (int i = 0; i < n + m + 1; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n + m + 1; i++) {
            cin >> b[i];
        }
        vector<ll> skill(n + m + 1);
        vector<int> assignment(n + m);
        ll sum = 0;
        int cnta = 0, cntb = 0;
        int which = 0;
        int idx = -2;
        for (int i = 0; i < n + m; i++) {
            if (which == 0 && cnta == n) {
                which = 1;
                idx = -1;
            } else if (which == 0 && cntb == m) {
                which = 2;
                idx = -1;
            }
            if (idx == -1) {
                if (which == 1 && a[i] > b[i]) {
                    idx = i;
                }
                if (which == 2 && a[i] < b[i]) {
                    idx = i;
                }
            }
            if (a[i] > b[i]) {
                if (cnta < n) {
                    cnta += 1;
                    sum += a[i];
                    assignment[i] = 1;
                } else {
                    cntb += 1;
                    sum += b[i];
                    assignment[i] = 2;
                }
            } else {
                if (cntb < m) {
                    cntb += 1;
                    sum += b[i];
                    assignment[i] = 2;
                } else {
                    cnta += 1;
                    sum += a[i];
                    assignment[i] = 1;
                }
            }
        }
        for (int i = 0; i < n + m; i++) {
            ll ans = sum;
            if (which == assignment[i]) {
                if (which == 1) {
                    ans -= a[i];
                    ans += (idx == -1 ? a[n + m] : a[idx] - b[idx] + b[n + m]);
                } else {
                    ans -= b[i];
                    ans += (idx == -1 ? b[n + m] : b[idx] - a[idx] + a[n + m]);
                }
            } else {
                if (assignment[i] == 1) {
                    ans -= a[i];
                    ans += a[n + m];
                } else {
                    ans -= b[i];
                    ans += b[n + m];
                }
            }
            cout << ans << " ";
        }
        cout << sum << " " << endl;
        // cerr << which << endl;
    }
}
