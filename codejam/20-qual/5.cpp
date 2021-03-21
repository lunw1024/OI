#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Bipartite {
    int n;
    vector<vector<bool>> edges;
    vector<int> o;
    vector<int> vis;

    Bipartite(int n) {
        this->n = n;
        edges.resize(n + 1, vector<bool>(n + 1));
        o.resize(n + 1, -1);
        vis.resize(n + 1);
    }

    void add_edge(int u, int v) {
        edges[u][v] = true;
        edges[v][u] = true;
    }

    bool dfs(int u, int tag) {
        vis[u] = tag;
        for (int v = 1; v <= n; v++) {
            if (!edges[u][v] && o[v] == -1) {
                o[u] = v, o[v] = u;
                return true;
            }
        }
        for (int v : edges[u]) {
            if (!edges[u][v] && vis[v] != tag && dfs(v, tag)) {
                o[u] = v, o[v] = u;
                return true;
            }
        }
        return false;
    }

    void manual_pair(int u, int v) {
        o[u] = v, o[v] = u;
        fill(edges[u].begin() + 1, edges[u].end(), false);
        fill(edges[v].begin() + 1, edges[v].end(), false);
    }

    vector<int> bipatite_pair() {
        for (int i = 1; i <= n; i++) {
            if (o[i] == -1)
                dfs(i, i);
        }
        return o;
    }
};

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;
        Bipartite graph(N);
        int a = K / N;
        int b = (K - a) / 2;
        int c = K - a - b;
        assert(a > 0 && b >= 0 && c >= 0);
        for (int i = 1; i <= N; i++) {
            for (int j = N + 1; j <= 2 * N; j++) {
                graph.add_edge(i, j);
            }
        }

        for (int i = 3; i <= N; i++) {
            if i == 1
        }
    }
}