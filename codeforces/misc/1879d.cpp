#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const ll MOD = 998244353;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int b = 0; b < 32; b++) {
        vector<ll> sum = {0, 0};
        vector<ll> cnt = {1, 0};
        ll parity = 0;
        ll base = 1 << b;
        for (int i = 0; i < n; i++) {
            if (a[i] & base) {
                parity = 1 - parity;
            }
            cnt[parity]++;
            sum[parity] = (sum[parity] + i + 1) % MOD;
            ans += base * ((cnt[parity ^ 1] * (i + 1) - sum[parity ^ 1]) % MOD);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

