#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y, y = t - (a / b) * y;
    return d;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll N, S, K;
        cin >> N >> S >> K;
        ll x, y;
        ll d = exgcd(K, N, x, y);
        if ((N - S) % d != 0)
            cout << -1 << endl;
        else {
            ll k = (N - S) / d;
            x *= k, y *= k;
            ll t = N / d;
            cout << ((x % t + t) % t) << endl;
        }
    }
}