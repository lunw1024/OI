#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto it = h.upper_bound(t);
        if (it == h.begin()) {
            cout << -1 << endl;
        } else {
            it = prev(it);
            cout << *it << endl;
            h.erase(it);
        }
    }
}

