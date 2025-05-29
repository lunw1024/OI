#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

ll power(ll a, ll x, ll MOD) {
    ll out = 1;
    while (x > 0) {
        if (x & 1) {
            out = out * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return out;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    const int m = int(1e9) + 7;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll k = power(b, c, m - 1);
        ll ans = power(a, k, m);
        cout << ans << endl;
    }
}

