#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
typedef long long ll;

const int MAXN = (int)3e5 + 1, MOD = 998244353;
int N, M;
vector<int> edges[MAXN];
ll v[MAXN][51];
int fa[MAXN][19], depth[MAXN];

void lca_dfs(int u, int prev, ll dep) {
    depth[u] = dep;
    fa[u][0] = prev;
    v[u][0] = 1;
    for (int i = 1; i <= 50; i++)
        v[u][i] = (v[u][i - 1] * dep) % MOD;
    // presum
    for (int i = 1; i <= 50; i++)
        if (prev != u) // not root
            v[u][i] = (v[u][i] + v[prev][i]) % MOD;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        lca_dfs(v, u, dep + 1);
    }
}

void preprocess() {
    lca_dfs(1, 0, 0);
    for (int k = 1; k <= 18; k++)
        for (int i = 1; i <= N; i++)
            fa[i][k] = fa[fa[i][k - 1]][k - 1];
}

int lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    for (int k = 18; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    for (int k = 18; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    preprocess();

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        int lca_ = lca(a, b);
        ll ans = ((v[a][k] + v[b][k] - v[lca_][k] - v[fa[lca_][0]][k]) % MOD + MOD) % MOD;
        cout << ans << endl;
    }
}