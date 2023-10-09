#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
const int MOD = 998244353;

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
    cin >> N >> M;
    ll product = 1;
    vector<char> s(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> s[i];
        if (i > 0 && s[i] == '?') {
            product = product * i % MOD;
        }
    }
    cout << (s[0] == '?' ? 0 : product) << endl;
    for (int q = 0; q < M; q++) {
        int i;
        char c;
        cin >> i >> c;
        i--;
        // cerr << s[i] << " -> " << c << endl;
        if (s[i] == c) {
            ;
        } else if (i == 0) {
            s[i] = c;
        } else if (s[i] == '?') {
            product = product * inv(i) % MOD;
            s[i] = c;
        } else if (c == '?') {
            product = product * i % MOD;
            s[i] = c;
        } else {
            s[i] = c;
        }
        cout << (s[0] == '?' ? 0 : product) << endl;
    }
}
