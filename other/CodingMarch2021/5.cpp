// from collections import Counter
// N = int(input())
// i = 0
// ss = {}
// ans = 0
// while i * i <= N:
//     s = tuple(sorted(Counter(str(i * i)).items()))
//     # print(s)
//     if s in ss:
//         ans += ss[s]
//         ss[s] += 1
//     else:
//         ss[s] = 1
//     i += 1
// print(ans)
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;
map<ll, ll> mp;

ll encode(ll x) {
    ll out = 0;
    vector<ll> a(10);
    while (x > 0) {
        a[x % 10]++;
        x /= 10;
    }
    for (ll i = 0, j = 1; i < 10; i++, j *= 13) {
        out += j * a[i];
    }
    return out;
}

int main() {
    cin >> N;
    ll ans = 0;
    for (ll i = 1; i * i <= N; i++) {
        int x = encode(i * i);
        if (mp.find(x) != mp.end()) {
            ans += mp[x];
            mp[x] += 1;
        } else {
            mp[x] = 1;
        }
    }
    cout << ans << endl;
}