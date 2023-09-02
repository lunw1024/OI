#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int ans = 0;
vector<vector<int>> edges;

int dfs(int u, int prev) {
    // cerr << "in node " << u << endl;
    vector<int> sz;
    int m = 0;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        sz.push_back(dfs(v, u));
        m += sz.back();
    }
    int n = sz.size();
    if (n == 0) {
        return 1;
    }
    vector<bool> dp(m);
    dp[0] = true;
    for (int x : sz) {
        for (int i = m - 1; i >= 0; i--) {
            if (i + x < m) {
                dp[i + x] = dp[i + x] || dp[i];
            }
        }
    }
    int best = 0;
    for (int i = 0; i < m; i++) {
        if (dp[i]) {
            best = max(best, i * (m - i));
            // cerr << i << " is ok" << endl;
        }
    }
    ans += best;
    return m + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    edges.resize(N);
    for (int i = 1; i < N; i++) {
        int j;
        cin >> j;
        j--;
        edges[i].push_back(j);
        edges[j].push_back(i);
    }
    dfs(0, 0);
    cout << ans << endl;
}
