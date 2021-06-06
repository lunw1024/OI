#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int INF = int(1e9);

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        ll L, R;
        bool flag;
        cin >> L >> R;
        if (L < R) {
            swap(L, R);
            flag = true;
        }
        ll d = L - R;
        ll l = 0, r = INF;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (d >= mid * (mid + 1) / 2)
                l = mid + 1;
            else
                r = mid - 1;
        }
        int ans = r, n = r;
        // cerr << "ans = " << ans << endl;
        L -= r * (r + 1) / 2;
        if (flag && L == R) {
            swap(L, R);
            flag = false;
        }
        l = 0, r = INF;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (L >= n * mid + mid * mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        ans += r;
        // cerr << "r1 = " << r << endl;
        L -= n * r + r * r; 
        l = 0, r = INF;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (R >= (n + 1) * mid + mid * mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        ans += r;
        // cerr << "r2 = " << r << endl;
        R -= (n + 1) * r + r * r;
        if (flag)
            swap(L, R);
        cout << "Case #" << t << ": " << ans << " " << L << " " << R << endl;
    }
}

