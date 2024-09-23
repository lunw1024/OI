#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const string types[] = {"BG", "BR", "BY", "GR", "GY", "RY"};

bool can_go(string a, string b) {
    return (a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1]);
}

int cost(int x, int y, int z) {
    if (y == 0 || y == int(1e9)) {
        return int(1e9);
    }
    return abs(x - y) + abs(y - z);
}

int main() {
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        int n, q;
        cin >> n >> q;
        vector<string> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        unordered_map<string, int> last_loc;
        vector<int> l(n + 1), r(n + 1);
        for (int i = 1; i <= n; i++) {
            // update last_loc
            last_loc[a[i]] = i;

            // update l
            int last = 0;
            for (string type : types) {
                if (type != a[i] && can_go(type, a[i])) {
                    int la = last_loc[type];
                    if (la != 0) {
                        last = max(la, last);
                    }
                }
            }
            l[i] = last; // 0 means dne
            // cerr << "l[" << i << "] = " << l[i] << endl;
        }
        last_loc.clear();
        for (int i = n; i >= 1; i--) {
            last_loc[a[i]] = i;
            int last = int(1e9);
            for (string type : types) {
                if (type != a[i] && can_go(type, a[i])) {
                    int la = last_loc[type];
                    if (la != 0) {
                        last = min(la, last);
                    }
                }
            }
            r[i] = last; // 1e9 means dne
            // cerr << "r[" << i << "] = " << r[i] << endl;
        }

        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            int ans = min((can_go(a[x], a[y]) ? abs(x - y) : int(1e9)), min(cost(x, l[x], y), cost(x, r[x], y)));
            cout << (ans == int(1e9) ? -1 : ans) << endl;
        }
    }
}
