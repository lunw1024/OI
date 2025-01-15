#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<vi> edges(n + 1);
        vi deg(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        vi ans(n + 1);
        int maxdeg = 0;
        int id = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                q.push(i);
            }
            if (deg[i] > maxdeg) {
                id = i;
            }
            maxdeg = max(maxdeg, deg[i]);
        }
        if (maxdeg == n - 1) {
            // special case
            assert(id != 0);
            for (int i = 1; i <= n; i++) {
                ans[i] = i * 2;
                ans[i] += i == id - 1;
                ans[i] -= i == id + 1;
            }
        } else {
            // topo sort
            int p = 3;
            // int first = 0;
            while (!q.empty()) {
                int u = q.front();
                // if (first == 0) {
                //     first = u;
                // }
                // cerr << "making" << u << endl;
                q.pop();
                // if (p == 2 * n - 1) {
                //     // special
                //     assert(q.size() == 1);
                //     int v = q.front();
                //     if (edges[first][0] == u) {
                //         swap(u, v);
                //     }
                //     ans[u] = 1;
                //     ans[v] = 2 * n - 1;
                //     break;
                // }
                ans[u] = p <= 2 * n ? p : 1;
                // cerr << "assign" << p << endl;
                p += 2;
                for (int v : edges[u]) {
                    deg[v]--;
                    if (deg[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

