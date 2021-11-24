#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = int(1e9) + 7;

int N;

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
    cin >> N;
    vector<ll> arr;
    for (int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        if (x % 2 == 0)
            arr.push_back(x / 2);
    }
    ll ans = 0;
    while (!arr.empty()) {
        vector<ll> e;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) {
                e.push_back(arr[i] / 2);
            }
        }
        int ne = e.size(), no = arr.size() - ne;
        if (no > 0) {
            ans = (power(2, no + ne - 1) + ans) % MOD;
        }
        arr = e;
    }
    ans = ((power(2, N) - ans - 1) % MOD + MOD) % MOD;
    cout << ans << endl;
}