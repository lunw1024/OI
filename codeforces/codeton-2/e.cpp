#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;
int N, M;
vector<ll> a;
vector<vector<int>> G, H;
vector<vector<ll>> vec;
vector<vector<bool>> inf;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (vis[v]) {
            continue;
        }
        dfs(v);
    }
    // cout << "on " << u << endl;
    // push dp
    vec[u][0] += a[u];
    if (vec[u][0] > N) {
        inf[u][0] = true;
        vec[u][0] %= MOD;
    }
    for (int v : H[u]) {
        // cout << "to " << v << endl;
        for (int i = 1; i < N; i++) {
            // cout << "at " << u << " pushing " << vec[u][i - 1] << " to " << v << endl;
            vec[v][i] += vec[u][i - 1];
            if (inf[u][i - 1] || inf[v][i] || vec[v][i] > N) {
                inf[v][i] = true;
                vec[v][i] %= MOD;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        int root = -1;
        G.clear();
        G.resize(N);
        H.clear();
        H.resize(N);
        vec.clear();
        vec.resize(N, vector<ll>(N, 0));
        a.clear();
        a.resize(N);
        vis.clear();
        vis.resize(N, false);
        inf.clear();
        inf.resize(N, vector<bool>(N, false));

        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // cout << u << " -> " << v << endl;
            G[v].push_back(u);
            H[u].push_back(v);
        }
        for (int i = 0; i < N; i++) {
            if (H[i].empty()) {
                root = i;
                break;
            }
        }
        // cout << "root = " << root << endl;
        dfs(root);
        ll end = 0;
        bool inff = false;
        for (int i = 0; i < N; i++) {
            // cout << vec[root][i] << " ";
            if (inff || end >= i) {
                end += vec[root][i];
                if (inf[root][i] || end > N) {
                    inff = true;
                }
            } else {
                if (inf[root][i] || vec[root][i] > 0) {
                    end = i;
                    end += vec[root][i];
                    if (inf[root][i] || end > N) {
                        inff = true;
                    }
                }
            }
        }
        cout << ((end + MOD) % MOD) << endl;
    }
}
