#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9 + 7, MAXN = (int)2e5 + 1;
ll inv[MAXN], fact[MAXN], f[MAXN];
int N, size[MAXN];
vector<int> edges[MAXN];

ll pow(ll a, int x) {
    ll out = 1;
    while (x > 0) {
        if (x & 1)
            out = out * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return out;
}

void dfs1(int u, int prev) {
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        dfs1(v, u);
        f[u] = f[u] * f[v] % MOD * inv[fact[size[v]]] % MOD;
        size[u] += size[v];
    }
}

int main() {
    cin >> N;
    inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        inv[i] = pow(i, MOD - 2);
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs1(1, 1);
}