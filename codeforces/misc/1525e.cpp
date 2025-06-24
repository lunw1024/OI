#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const ll MOD = 998244353;

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

ll inv(ll x) {
    return power(x, MOD - 2);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(m));
    vector<ll> p(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dist[i][j];
        }
    }
    ll ans = 0;
    for (int j = 0; j < m; j++) {
        p[j] = 1;
        double x = 1;
        vector<int> cnt(n + 2);
        for (int i = 0; i < n; i++) {
            cnt[dist[i][j]]++;
        }
        int pre = 0;
        for (int d = 1; d <= n + 1; d++) {
            for (int k = 0; k < cnt[d]; k++) {
                int candidates = d - 1 - pre;
                if (candidates <= 0) {
                    p[j] = 0;
                    x = 0;
                } else {
                    p[j] = (p[j] * candidates % MOD * inv(n - pre)) % MOD;
                    x *= double(candidates) / n;
                }
                pre++;
            }
        }
        assert(pre == n);
        // cerr << "p[" << j << "] = " << x << endl;
        p[j] = (MOD + 1 - p[j]) % MOD;
        ans = (ans + p[j]) % MOD;
    }
    cout << ans << endl;
}

