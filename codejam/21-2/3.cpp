#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll MOD = ll(1e9) + 7;
const int MAXN = int(1e5);
int N;
vector<int> arr;
vector<ll> fact, inv;
vector<vector<int>> bigs;

ll quickpow(ll a, ll x) {
    ll out = 1;
    while (x > 0) {
        if (x & 1)
            out = out * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return out;
}

void preprocess() {
    fact.resize(MAXN + 1);
    fact[0] = 1;
    for (ll i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv.resize(MAXN + 1);
    inv[MAXN] = quickpow(fact[MAXN], MOD - 2);
    for (ll i = MAXN - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll C(int n, int k) {
    if (n == k || k == 0)
        return 1;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
} 

int find_big(int val) {
    int out = bigs[val].back();
    bigs[val].pop_back();
    return out;
}

ll solve(int l, int r, int val) {
    if (l >= r) {
        if (l == r)
            find_big(val);
        return 1ll;
    }
    // find biggest
    int big = find_big(val); // find last min
    // cerr << "dividing [" << l << ", " << r << "] at " << big << endl;
    ll ansr = solve(big + 1, r, val + 1);
    ll ansl = solve(l, big - 1, val);
    // cerr << "in [" << l << ", " << r << "], " << "ansl = " << ansl << ", ansr = " << ansr << ", C = " << C(r - l, r - big) << ", big = " << big << endl;
    return ansl * ansr % MOD * C(r - l, r - big) % MOD;
}

int main() {
    int T;
    cin >> T;
    preprocess();
    for (int t = 1; t <= T; t++) {
        cin >> N;

        arr.clear();
        arr.resize(N + 1);
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        // check
        bool flag = true;
        for (int i = 2; i <= N; i++) {
            if (arr[i] > arr[i - 1] + 1)
                flag = false;
        }
        if (!flag) {
            cout << "Case #" << t << ": " << 0 << endl;
            continue;
        }
        
        bigs.clear();
        bigs.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            bigs[arr[i]].push_back(i);
        }

        ll ans = solve(1, N, 1);
        cout << "Case #" << t << ": " << ans << endl;
    }
}