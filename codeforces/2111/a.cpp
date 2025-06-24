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
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int x;
        cin >> x;
        multiset<int> s = {0, 0, 0};
        int ans = 0;
        while (*s.begin() < x) {
            // cerr << s.size() << endl;
            int a = *s.begin();
            int b = *next(s.begin());
            int c = min(x, b * 2 + 1);
            s.erase(s.find(a));
            s.insert(c);
            ans++;
        }
        cout << ans << endl;
    }
}

