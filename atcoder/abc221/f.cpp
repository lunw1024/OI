#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;
int N, maxd = 0, x = 0;
vector<vector<int>> edges;

void dfs(int u, int prev, int d) {
    if (d >= maxd) {
        maxd = d;
        x = u;
    }
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        dfs(v, u, d + 1);
    }
}

bool path(int a, int b, int prev, vector<int>& out) {
    if (a == b) {
        out.push_back(b);
        return true;
    }
    for (int v : edges[a]) {
        if (v == prev)
            continue;
        if (path(v, b, a, out)) {
            out.push_back(a);
            return true;
        }
    }
    return false;
}

ll dp(int u, int prev, int mask, int d, int target) {
    ll out = 0;
    if (d == target) {
        assert(edges[u].size() == 1);
        return 1;
    }

    for (int v : edges[u]) {
        if (v == prev || v == mask)
            continue;
        out += dp(v, u, mask, d + 1, target);
    }
    return out;
}

int main() {
    cin >> N;
    edges.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 1, 0);
    int a = x;
    maxd = 0;
    dfs(a, a, 0);
    int b = x;

    vector<int> p;
    path(a, b, a, p);

    assert(p.size() == maxd + 1);
    ll ans = 0;
    if (p.size() % 2 == 0) {
        int x = p[p.size() / 2 - 1], y = p[p.size() / 2];
        ans = dp(x, x, y, 0, maxd / 2) * dp(y, y, x, 0, maxd / 2) % MOD;
    } else {
        int c = p[p.size() / 2];
        vector<int> v;
        for (int u : edges[c]) {
            v.push_back(dp(u, u, c, 0, maxd / 2 - 1));
        }
        ans = 1;
        for (int i : v)
            ans = ans * (i + 1) % MOD;
        for (int i : v)
            ans = (ans - i + MOD) % MOD;
        ans = (ans - 1 + MOD) % MOD;
    }
    cout << ans << endl;
}