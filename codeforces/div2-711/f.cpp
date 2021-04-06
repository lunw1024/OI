// if k = 1, even nodes are useless
// for general k, len = floor(d / K)
// then, len is even -> useless
// what about for every root?
// preprocess xor-sum of every residual group (distance between nodes == K)
// dfs reroot

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector<vector<int>> edges, G;
vector<int> V, ans;

void preprocess(int u, int prev) { 
    G[u][0] ^= V[u];
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        preprocess(v, u);
        for (int i = 0; i < 2 * K - 1; i++)
            G[u][i+1] ^= G[v][i];
        G[u][0] ^= G[v][2*K-1];
    }
    // cerr << "preprocessing node " << u << endl;
    // for (int i = 0; i < 2 * K; i++)
    //     cerr << G[u][i] << " ";
    // cerr << endl;
}

void solve(int u, int prev, const vector<int>& parent) {
    vector<int> sum = parent;
    // remove (unshifted) subtree contribution
    if (u != prev) { // skip for root for convenience
        for (int i = 0; i < 2 * K - 1; i++)
            sum[i+1] ^= G[u][i];
        sum[0] ^= G[u][2*K-1];
    }
    // shift +1
    int temp = sum[2*K-1];
    for (int i = 2*K-1; i >= 1; i--)
        sum[i] = sum[i - 1];
    sum[0] = temp;
    // add subtree back
    for (int i = 0; i < 2*K; i++)
        sum[i] = sum[i] ^ G[u][i];

    // record answer
    int value = 0;
    for (int i = K; i < 2*K; i++)
        value ^= sum[i];
    ans[u] = value != 0;

    // cerr << "in node " << u << endl;
    // for (int i = 0; i < 2*K; i++)
    //     cerr << sum[i] << " ";
    // cerr << endl;
    // cerr << "value for " << u << " = " << value << endl;

    for (int v : edges[u]) {
        if (v == prev)
            continue;
        
        solve(v, u, sum);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> K;
    edges.resize(N + 1, vector<int>());
    V.resize(N + 1);
    G.resize(N + 1, vector<int>(2*K));
    ans.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        cin >> V[i];
    
    preprocess(1, 1);

    solve(1, 1, vector<int>(2*K));

    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << endl;
}
