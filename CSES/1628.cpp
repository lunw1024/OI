#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> A = {0}, B = {0};
    for (int i = 0; i < min(n, 20); i++) {
        vector<ll> to_add;
        to_add.reserve(A.size());
        int y = a[i];
        for (ll k : A) {
            to_add.emplace_back(k + y);
        }
        for (auto v : to_add) {
            A.emplace_back(v);
        }
    }
    for (int i = 20; i < n; i++) {
        vector<ll> to_add;
        to_add.reserve(B.size());
        int y = a[i];
        for (ll k : B) {
            to_add.emplace_back(k + y);
        }
        for (auto v : to_add) {
            B.emplace_back(v);
        }
    }
    // sort(A.begin(), A.end());
    map<ll, ll> cnt;
    for (ll y : B) {
        if (!cnt.contains(y)) {
            cnt[y] = 0;
        }
        cnt[y]++;
    }
    ll ans = 0;
    for (ll v : A) {
        if (cnt.contains(x - v)) {
            ans += cnt[x - v];
        }
    }
    cout << ans << endl;
}

