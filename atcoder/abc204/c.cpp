#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<vector<int>> edges;
vector<bool> vis;

int dfs(int u) {
    vis[u] = true;
    int out = 1;
    for (int v : edges[u]) {
        if (!vis[v])
            out += dfs(v);
    }
    return out;
}

int main() {
    cin >> N >> M;
    edges.resize(N + 1);
    vis.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        fill(vis.begin(), vis.end(), false);
        ans += dfs(i);
    }
    cout << ans << endl;
}