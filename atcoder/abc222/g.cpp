// https://atcoder.jp/contests/abc222/tasks/abc222_g
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll power(ll a, ll x, ll m) {
    ll out = 1;
    while (x > 0) {
        if (x & 1) {
            out = out * a % m;
        }
        a = a * a % m;
        x >>= 1;
    }
    return out;
}

ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b % a, a);
}

ll BSGS(ll a, ll b, ll m) { // a^x % m = b
    if (gcd(a, m) > 1)
        return -1;
    ll root = ll(sqrt(m));
    ll l = 1, r = b; // step a^root, a
    ll dl = ll(ceil(power(a, root, m))), dr = a;
    unordered_map<ll, int> mp;
    for (int i = 0; i < root; i++) {
        mp[r] = i;
        r = r * dr % m;
    }
    for (int i = 1; i <= root + 1; i++) {
        l = l * dl % m;
        auto it = mp.find(l);
        if (it != mp.end())
            return root * i - (*it).second;
    }
    assert(false);
}

int N;

int main() {
    cin >> N;
    for (int t = 0; t < N; t++) {
        ll K;
        cin >> K;
        ll m = K % 2 == 0 ? 9 * K / 2 : 9 * K;
        ll ans = BSGS(10, 1, m);
        cout << (ans == -1 ? -1 : max(1ll, ans)) << endl;
    }
}
