#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const ll MOD = 998244353;
int N;
vector<vector<int>> edges;
vector<ll> deg, fact, pow2;

ll power(ll a, ll x) {
    ll out = 1;
    while (x > 0) {
        if (x & 1) {
            out = out * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return out;
}

ll inv(ll x) {
    return power(x, MOD - 2);
}

pii dfs(int u, int prev) {
    ll ret = 1, free = u != prev;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        pii a = dfs(v, u);
        ret = ret * a.first % MOD;
        if (a.second % 2 == 1)
            free++;
    }
    ll n = free - free % 2;
    ret *= fact[n] * inv(fact[n / 2]) % MOD * inv(pow2[n / 2]) % MOD;
    ret %= MOD;
    return make_pair(ret, free);
}

int main() {
    cin >> N;
    edges.resize(N + 1);
    deg.resize(N + 1);
    fact.resize(N + 1);
    pow2.resize(N + 1);
    fact[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    ll ans = dfs(1, 1).first;
    cout << ans << endl;
}
