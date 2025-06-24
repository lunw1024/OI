#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, q;
        cin >> n >> q;
        vi b(n), l(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            l[i] = b[i];
        }
        vector<tuple<int, int, int>> Q;
        for (int i = 0; i < q; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--, z--;
            Q.emplace_back(x, y, z);
        }
        for (auto& [x, y, z] : Q | views::reverse) {
            int lx = l[x], ly = l[y], lz = l[z];
            l[z] = 0;
            l[x] = max(lx, lz);
            l[y] = max(ly, lz);
            // cerr << "l[" << x << "] := " << l[x] << endl;
            // cerr << "l[" << y << "] := " << l[y] << endl;
        }
        // sim
        vi ans = l;
        for (auto& [x, y, z] : Q) {
            l[z] = min(l[x], l[y]);
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= l[i] == b[i];
            // cerr << l[i] << " ";
        }
        // cerr << endl;
        if (ok) {
            for (int x : ans) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

