#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int dfs(int u, int target, int source, vector<bool>& vis, vector<vi>& G, vi& stack) {
    if (vis[u]) {
        return 0;
    }
    vis[u] = true;
    stack.push_back(u);
    int ret = 0;
    for (int v : G[u]) {
        if (v == target) {
            if (u == source) {
                // inital
                continue;
            } else {
                return u; // found second
            }
        }
        ret = max(ret, dfs(v, target, source, vis, G, stack));
        if (ret != 0) {
            break;
        }
    }
    if (ret != 0) {
        return ret;
    } else {
        stack.pop_back();
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vector<vi> G(n + 1);
        vi d(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            d[u]++;
            d[v]++;
        }
        bool answered = false;
        for (int i = 1; i <= n; i++) {
            if (d[i] >= 4) {
                // int a = 0, b = 0;
                vector<bool> vis(n + 1);
                vi stack;
                for (int u : G[i]) {
                    int v = dfs(u, i, u, vis, G, stack);
                    if (v != 0) {
                        assert(stack.size() >= 2);
                        // cut cycle
                        vector<pii> children = {{0, u}, {stack.size() - 1, v}};
                        vi orphans;
                        int p = -1;
                        for (int j = 0; j < 2; j++) {
                            p++;
                            while (G[i][p] == u || G[i][p] == v) {
                                p++;
                            }
                            auto it = find(stack.begin(), stack.end(), G[i][p]);
                            if (it == stack.end()) {
                                orphans.push_back(G[i][p]);
                            } else {
                                children.push_back({it - stack.begin(), G[i][p]});
                            }
                        }
                        sort(children.begin(), children.end());
                        // cerr << "children size = " << children.size() << endl;
                        int end = children[1].first + 1;
                        while (stack.size() > end) {
                            stack.pop_back();
                        }
                        for (int j = 2; j < children.size(); j++) {
                            orphans.push_back(children[j].second);
                        }
                        
                        // print ans
                        answered = true;
                        cout << "YES" << endl;
                        cout << 4 + stack.size() - 1 << endl;
                        // cycle1
                        for (int j = 0; j < stack.size() - 1; j++) {
                            cout << stack[j] << " " << stack[j + 1] << endl;
                        }
                        cout << i << " " << children[0].second << endl;
                        cout << i << " " << children[1].second << endl;
                        cout << i << " " << orphans[0] << endl;
                        cout << i << " " << orphans[1] << endl;
                        break;
                    }
                }
                if (answered) {
                    break;
                }
            }
        }
        if (!answered) {
            cout << "NO" << endl;
        }
    }
}

