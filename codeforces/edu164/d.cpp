#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int MOD = 998244353;

ll f(int x, int s) {
    return ll(x >= s ? x : (x + s + 1) / 2);
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> cnt(5000 + 1); // number of sets that has sum i
    ll ans = 0;
    cnt[0] = 1;
    for (int i = 0; i < N; i++) {
        // cout << "for " << a[i] << endl;
        for (int j = 5000; j >= a[i]; j--) {
            ans += cnt[j - a[i]] * f(a[i], j - a[i]) % MOD;
            // cout << "+ " << (cnt[j - a[i]] * f(a[i], j - a[i])) << endl;
            ans %= MOD;
            cnt[j] = (cnt[j] + cnt[j - a[i]]) % MOD;
            // cout << "cnt[" << j << "] = " << cnt[j] << endl;
        }
    }
    cout << ans << endl;
}
