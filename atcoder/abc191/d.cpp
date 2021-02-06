#include <atcoder/all>
#include <iostream>
#include <cmath>
using namespace atcoder;
using namespace std;
using ld = long double;
using ll = long long;
 
ld X, Y, R;
ld eps = 1e-8; // this is total garbage
 
bool in(ll x, ll y) {
    return (X - x) * (X - x) + (Y - y) * (Y - y) < R * R + eps;
}

int main() {
    cin >> X >> Y >> R;
    ll ans = 0;
    for (ll y = ll(ceil(Y - R)) - 2; y <= ll(Y + R) + 2; y++) {
        if (!in(X, y))
            continue;
        ld k = sqrt(R * R - (Y - y) * (Y - y));
        ld l = X - k, r = X + k;
        ll left = ll(ceil(l)), right = ll(r);
        // check left
        if (in(left - 1, y))
            ans++;
        if (!in(left, y))
            ans--;
        // check right
        if (!in(right, y))
            ans--;
        if (in(right + 1, y))
            ans++;
        ans += ll(r) - ll(ceil(l)) + 1;
        // cout << y << " " << l << " " << r << endl;
    }
    cout << ans << endl;
}