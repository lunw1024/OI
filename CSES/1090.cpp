#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x;
    cin >> n >> x;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        s.insert(y);
    }
    int ans = 0;
    while (!s.empty()) {
        // cerr << s.size() << endl;
        ans++;
        int fat = *s.rbegin();
        s.erase(prev(s.end()));
        auto skinny_it = s.upper_bound(x - fat);
        if (skinny_it != s.begin()) {
            skinny_it = prev(skinny_it);
            s.erase(skinny_it);
        } else {
            continue;
        }
    }
    cout << ans << endl;
}
