#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 50001;
int N, K;
ll ans = 0;
vector<int> edges[MAXN];
int sz[MAXN];
bool deleted[MAXN];

void preprocess_size(int u, int prev) {
    sz[u] = 1;
    for (int v : edges[u]) {
        if (v == prev || deleted[v])
            continue;
        preprocess_size(v, u);
        sz[u] += sz[v];
    }
}

int pathCnt[501], temp[501];
void dfs(int u, int prev, int d) {
    if (d > K)
        return;
    ans += pathCnt[K - d];
    temp[d]++;
    for (int v : edges[u]) {
        if (v == prev || deleted[v])
            continue;
        dfs(v, u, d + 1);
    }
}

void solve(int c) { // c is a centroid
    fill(pathCnt, pathCnt + K + 1, 0);
    pathCnt[0] = 1;
    for (int v : edges[c]) {
        if (deleted[v])
            continue;
        fill(temp, temp + K + 1, 0);
        dfs(v, c, 1);
        for (int i = 0; i <= K; i++)
            pathCnt[i] += temp[i];
    }
}

int dfs_centroid(int u, int prev, int n) {
    int out = u;
    for (int v : edges[u]) {
        if (v == prev || deleted[v])
            continue;
        if (sz[v] > n / 2)
            out = -1;
        int childAns = dfs_centroid(v, u, n);
        if (childAns > 0)
            return childAns;
    }
    if (n - sz[u] > n / 2)
        out = -1;
    return out;
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        preprocess_size(x, x);
        // find centroid
        int n = sz[x];
        int c = dfs_centroid(x, x, n);
        if (c == -1)
            cout << "ERROR" << endl;
        solve(c);
        for (int v : edges[c]) {
            if (deleted[v])
                continue;
            que.push(v);
        }
        deleted[c] = true;
    }
    cout << ans << endl;
}