// dp on tree (with another dp for fast transferrence)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;
int N, K;
vector<vector<int>> edges;
vector<vector<ll>> dp;

int dfs(int u, int prev) {
    int h = 0;
    dp[u][0] = 1;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        int h0 = dfs(v, u);
        int len = min(K, max(h, h0 + 1));
        // merge dp
        // take
        vector<ll> temp(len + 1);
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j <= h0; j++) {
                if (i + j + 1 > K)
                    continue;
                temp[max(i, j + 1)] += dp[v][j] * dp[u][i] % MOD;
                temp[max(i, j + 1)] %= MOD;
            }
        }
        // not take
        ll sum = 0;
        for (int i = 0; i <= min(h0, K); i++) {
            sum = (sum + dp[v][i]) % MOD;
        }
        for (int i = 0; i <= len; i++) {
            dp[u][i] = (dp[u][i] * sum % MOD + temp[i]) % MOD;
        }
        
        h = max(h, h0 + 1);
    }
    return h;
}

int main() {
    cin >> N >> K;
    edges.resize(N + 1);
    dp.resize(N + 1, vector<ll>(K + 1));
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 1);

    ll ans = 0;
    for (int i = 0; i <= K; i++) {
        ans += dp[1][i];
        ans %= MOD;
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 0; j <= K; j++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    cout << ans << endl;
}