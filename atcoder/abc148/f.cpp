#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = (int)1e5 + 1;
int N, A, B, dist[MAXN], depth[MAXN];
bool vis[MAXN] = {0};
vector<int> edges[MAXN];

void dfs(int u, int (&arr)[MAXN]) {
    for (int v : edges[u]) {
        if (arr[v] == (int)1e9) {
            arr[v] = arr[u] + 1;
            dfs(v, arr);
        }
    }
}

int main() {
    cin >> N >> A >> B;
    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    fill(dist + 1, dist + 1 + N, (int)1e9);
    dist[A] = 0;
    dfs(A, dist);
    fill(depth + 1, depth + 1 + N, (int)1e9);
    depth[B] = 0;
    dfs(B, depth);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] < depth[i]) {
            ans = max(ans, depth[i] - 1);
        }
    }
    cout << ans << endl;
}