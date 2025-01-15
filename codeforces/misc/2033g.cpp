#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

int init_st(int u, int prev, int d, vector<vector<int>> &G, vector<vector<int>>& fa, vector<int>& depth, vector<int>& d1, vector<int>& d2) {
    fa[u][0] = prev;
    depth[u] = d;
    int best = 0, second = 0;
    for (int v : G[u]) {
        if (v == prev) {
            continue;
        }    
        int ret = init_st(v, u, d + 1, G, fa, depth, d1, d2) + 1;
        second = max(second, ret);
        if (second > best) {
            swap(best, second);
        }
    }
    d1[u] = best;
    d2[u] = second;
    return best;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        // preprocess sparse table
        const int maxlog = static_cast<int>(floor(log2(n)));
        vector<vector<int>> st(n + 1, vector<int>(maxlog + 1));
        vector<vector<int>> fa(n + 1, vector<int>(maxlog + 1));
        vector<int> depth(n + 1), d1(n + 1), d2(n + 1);
        init_st(1, 1, 0, G, fa, depth, d1, d2);
        for (int i = 2; i <= n; i++) {
            int parent = fa[i][0];
            // cerr << parent << " -> " << i << endl;
            // cerr << "d1[parent] = " << d1[parent] << ", d1[i] = " << d1[i] << endl;
            if (d1[i] + 1 == d1[parent]) {
                st[i][0] = d2[parent] - depth[parent];
            } else if (d1[i] + 1 < d1[parent]) {
                st[i][0] = d1[parent] - depth[parent];
            } else {
                throw logic_error("this is impossible");
            }
            // cerr << "st[" << i << "][" << 0 << "] = " << st[i][0] << endl;
        }
        for (int i = 1; i <= maxlog; i++) {
            for (int v = 1; v <= n; v++) {
                fa[v][i] = fa[fa[v][i - 1]][i - 1];
                st[v][i] = max(st[v][i - 1], st[fa[v][i - 1]][i - 1]);
                // cerr << "st[" << v << "][" << i << "] = " << st[v][i] << endl;
            }
        }
        
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int v, k;
            cin >> v >> k;
            int ans = d1[v];
            int dv = depth[v];
            // cerr << "finding ans for (" << v << ", " << k << ")" << endl;
            for (int j = 0; k > 0; j++) {
                if (k & 1) {
                    // cerr << "adding st[" << v << "][" << j << "]" << endl;
                    int candidate = st[v][j] + dv;
                    ans = max(ans, candidate);
                    v = fa[v][j];
                }
                k >>= 1;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}
