#include <iostream>
#include <vector>
using namespace std;

bool path_to_target(vector<vector<int>>& G, int u, int prev, int target, vector<int>& path) {
    if (u == target) {
        path.push_back(u);
        return true;
    }
    for (int v : G[u]) {
        if (v == prev) {
            continue;
        }
        bool found = path_to_target(G, v, u, target, path);
        if (found) {
            path.push_back(u);
            return true;
        }
    }
    return false;
}

int depth(vector<vector<int>>& G, int u, int prev) {
    // returns depth
    int out = 0;
    for (int v : G[u]) {
        if (v == prev) {
            continue;
        }
        out = max(out, 1 + depth(G, v, u));
    }
    return out;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<vector<int>> G(n);
        int a, b;
        cin >> a >> b;
        a--; b--;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> path;
        path_to_target(G, a, a, b, path);
        // for (int y : path) {
        //     cerr << y << ", ";
        // }
        // cout << endl;
        int x = path[path.size() - 1 - (path.size() - 1) / 2];
        int d = depth(G, x, x);
        cout << (n - 1) * 2 - d + (path.size() / 2) << endl;
    }
}
