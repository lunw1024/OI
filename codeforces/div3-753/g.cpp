// MVT
// How to find ops with the final balance?
// Is greedy ok? parity?
// parity after each plate is the same through all possibilties, so yes

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll sign(ll x) {
    if (x == 0)
        return 0;
    return x / abs(x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(n);
        ll A = 0, B = 0, D = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            A += min(m, a[i]);
            B += min(m, b[i]);
            D += a[i] - b[i];
        }
        ll minD = D - A + (n * m - A), maxD = D + B - (n * m - B);
        // cout << "Case " << T << ": " << minD << " " << maxD << "\n";
        ll ansD = 0;
        if (sign(minD) == sign(maxD)) {
            ansD = abs(minD) < abs(maxD) ? minD : maxD;
        } else {
            ansD = maxD % 2 == 1 ? 1 : 0;
        }
        // reconstruct
        ll lowerbound = 0;
        for (int i = 0; i < n; i++) {
            lowerbound += max(0ll, m - b[i]);
        }
        ll toeat = (D - ansD + n * m) / 2 - lowerbound;
        cout << abs(ansD) << "\n";
        for (int i = 0; i < n; i++) {
            ll x = min(toeat + max(0ll, m - b[i]), min(m, a[i]));
            ll y = m - x;
            toeat -= x - max(0ll, m - b[i]);
            cout << x << " " << y << "\n";
        }
    }
    cout << endl;
}
