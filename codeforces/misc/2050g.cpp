#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int dfs(vector<vi>& G, int u, int prev, int& ans) {
    int s = static_cast<int>(G[u].size());
    int ret = s - 1;
    int first = 0, second = 0;
    for (int v : G[u]) {
        if (v == prev) {
            continue;
        }
        
        int x = dfs(G, v, u, ans);
        second = max(second, x);
        if (second > first) {
            swap(first, second);
        }
    }
    ret = max(ret, s - 2 + first);
    // update ans by picking one ot two best children
    ans = max(ans, s);
    ans = max(ans, s - 1 + first);
    ans = max(ans, s - 2 + first + second);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<vi> G(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int ans = 0;
        dfs(G, 1, 1, ans);
        cout << ans << endl;
    }
}

