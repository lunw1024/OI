#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using pii = pair<int, int>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vector<pii> s;
    int a = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.emplace_back(x, x);
        a = max(a, x);
    }
    vi ans;
    ans.emplace_back(a);
    while (!s.empty()) {
        bool flag = true;
        vector<pii> t;
        int b = -1, real = -1;
        for (auto [u, v] : s) {
            if (flag && v == a) {
                flag = false;
                continue;
            }
            int f = u & (~a);
            t.emplace_back(f, v);
            if (b < f) {
                b = f;
                real = v;
            }
        }
        swap(s, t);
        if (b <= 0) {
            break;
        }
        ans.emplace_back(real);
        a = real;
    }
    for (auto [x, y] : s) {
        ans.emplace_back(y);
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

