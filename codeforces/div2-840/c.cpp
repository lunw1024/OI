#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        vector<ll> a(N);
        ll mx = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        int l = N - 1, r = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] == mx) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        ll ans = 0;
        if (l < N - 2 || r > 1) {
            ans = N * mx;
        } else {
            // a mx b or a mx or mx b
            if (N == 2) {
                ans = max(a[0] + a[1], 2 * abs(a[0] - a[1]));
            } else { // N == 3
                ans = max(a[0] * 3, max(a[2] * 3, max(abs(a[1] - min(a[0], a[2])) * 3, a[0] + a[1] + a[2])));
            }
        }
        cout << ans << endl;
    }
}
