#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;
int N, K;

ll power(ll a, ll x) {
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

ll fact(ll x) {
    ll out = 1;
    for (ll i = 1; i <= x; i++)
        out = out * i % MOD;
    return out;
}

ll inv(ll x) {
    return power(x, MOD - 2);
}

ll comb(ll n, ll m) {
    if (n < m)
        return 0;
    return fact(n) * inv(fact(m)) % MOD * inv(fact(n - m)) % MOD;
}

int main() {
    cin >> N >> K;
    vector<int> s(N), p(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        p[s[i]] = i;
    }
    p[N] = -1;
    int m = N - 1;
    for (int i = 0; i < N - 1; i++) {
        if (p[s[i] + 1] >= p[s[i + 1] + 1]) {
            m--;
        }
    }
    cerr << K << " " << m << " " << N << endl;
    ll ans = comb(K + m, N);
    cout << ans << endl;
}