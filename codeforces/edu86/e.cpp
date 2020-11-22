#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
int N, K;
ll fact[(int)2e5 + 1] = {0};
ll ans = 0;

ll quick_pow(ll a, int x) {
    ll out = 1;
    while (x > 0) {
        if (x & 1)
            out = out * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return out;
}

ll inv(ll x) {
    return quick_pow(x, MOD - 2);
}

ll comb(int n, int x) {
    return fact[n] * inv(fact[n - x]) % MOD * inv(fact[x]) % MOD;
}

int main() {
    cin >> N >> K;

    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    if (K >= N) {
        ans = 0;
    } else {
        int c = N - K;
        for (int i = 0; i < c; i++) {
            ll sign = 1 - i % 2 * 2;
            ans = (ans + sign * comb(c, i) * quick_pow(c - i, N)) % MOD;
        }
        ans = ans * comb(N, c) * (K == 0 ? 1 : 2) % MOD;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}