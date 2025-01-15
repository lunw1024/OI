#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
using ll = long long;

const int MOD = static_cast<int>(1e9) + 7;

ll fastpow(ll a, int x) {
    ll out = 1;
    while (x > 0) {
        if (x & 1) {
            out = (out * a) % MOD;
        }
        x >>= 1;
        a = (a * a) % MOD;
    }
    return out;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        ll ans = 0;
        stack<pair<int, int>> s; // (base, #2s)
        for (int i = 0; i < n; i++) {
            int x = 0;
            int exp = 0;
            cin >> x;
            while (!(x & 1)) {
                exp++;
                x >>= 1;
            }
            // cerr << x << "* 2^" << exp << endl;
            while (!s.empty()) {
                pair<int, int> top = s.top();
                if (static_cast<int>(log2(top.first / x)) < exp) {
                    ans = (ans - top.first * fastpow(2, top.second) + top.first) % MOD;
                    exp += top.second;
                    s.pop();
                    // cerr << "pop" << endl;
                } else {
                    break;
                }
            }
            s.push(make_pair(x, exp));
            ans += (x * fastpow(2, exp)) % MOD;
            ans = (ans + MOD) % MOD;
            cout << ans << " ";
        }
        cout << endl;
        
    }
}
