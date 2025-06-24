#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void pop(map<int, map<int, map<int, int>>>& points, int x, int y, int z) {
    points[x][y].erase(z);
    if (points[x][y].size() == 0) {
        points[x].erase(y);
    }
    if (points[x].size() == 0) {
        points.erase(x);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    map<int, map<int, map<int, int>>> points;
    vector<tuple<int, int, int>> all_points;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (points.count(x) == 0) {
            points[x] = map<int, map<int, int>>();
        }
        if (points[x].count(y) == 0) {
            points[x][y] = map<int, int>();
        }
        points[x][y][z] = i + 1;
        all_points.emplace_back(x, y, z);
    }
    vector<pii> ans;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        auto [x, y, z] = all_points[i - 1];
        pop(points, x, y, z);
        // cerr << "size = " << points.size() << endl;
        auto itx = points.upper_bound(x);
        if (itx != points.begin()) {
            itx--;
        }
        auto ity = (*itx).second.upper_bound(y);
        if (ity != (*itx).second.begin()) {
            ity--;
        }
        auto itz = (*ity).second.upper_bound(z);
        if (itz != (*ity).second.begin()) {
            itz--;
        }
        int idx = (*itz).second;
        auto [x1, y1, z1] = all_points[idx - 1];
        pop(points, x1, y1, z1);
        // cerr << "pairing (" << x << ", " << y << ", " << z << ") with (" << x1 << ", " << y1 << ", " << z1 << ")" << endl;
        ans.emplace_back(i, idx);
        vis[i] = true;
        vis[idx] = true;
    }
    assert(ans.size() == n / 2);
    for (auto [a, b] : ans) {
        cout << a << " " << b << endl;
    }
}

