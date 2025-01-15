#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;
using ld = long double;

struct BIT {
    int n;
    vector<ll> data;
    BIT(int n_) {
        n = n_;
        data.resize(n);
    }

    int lowbit(int x) {
        return x & (-x);
    }

    ll prefix(int x) {
        ll out = 0;
        while (x > 0) {
            out += data[x];
            x -= lowbit(x);
            // cerr << "prefix" << endl;
        }
        return out;
    }

    void add(int x, ll k) {
        while (x < n) {
            data[x] += k;
            x += lowbit(x);
            // cerr << "add" << endl;
        }
    }
};

struct Arctan {
    ll x, y;
    Arctan(ll x_=0, ll y_=0) {
        x = x_;
        y = y_;
    }

    bool operator<(Arctan o) {
        if (x < 0 && o.x >= 0) {
            return false;
        }
        if (x >= 0 && o.x < 0) {
            return true;
        }
        return x * o.y > o.x * y;
    }
};

bool comp(pair<pair<Arctan, int>, int> a, pair<pair<Arctan, int>, int> b) {
    return a.first.first < b.first.first;
}

bool comp1(pair<Arctan, int> a, pair<Arctan, int> b) {
    return a.first < b.first;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<Arctan, int>> right(n);
    vector<ll> value(n);
    vector<pair<pair<Arctan, int>, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x, y, val;
        cin >> x >> y >> val;
        value[i] = val;
        Arctan l(x, y), r(x-k, y);
        v[i].first.first = l;
        v[i].second = i;
        right[i].first = r;
        right[i].second = i;
    }
    // cerr << "111" << endl;
    sort(right.begin(), right.end(), comp1);
    for (int i = 0; i < n; i++) {
        v[right[i].second].first.second = i + 1;
        // cerr << "set " << right[i].second << " -> " << i + 1 << endl;
    }
    // cerr << "222" << endl;
    sort(v.begin(), v.end(), comp);
    vector<ll> ans(n);
    BIT bit(n + 1);
    // cerr << "333" << endl;
    for (pair<pair<Arctan, int>, int> p : v) {
        // cerr << "yo" << endl;
        // cerr << p.first.second << endl;
        ans[p.second] = bit.prefix(n) - bit.prefix(p.first.second);
        bit.add(p.first.second, value[p.second]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}
