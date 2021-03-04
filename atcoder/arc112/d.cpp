// . . .
//       .
//       .
//       .

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
vector<bool> vis;
vector<vector<int>> edges;

void dfs(int u) {
    vis[u] = true;
    for (int v : edges[u])
        if (!vis[v])
            dfs(v);
}

int main() {
    cin >> H >> W;
    edges.resize(H + W);
    vis.resize(H + W);
    for (int i : {0, H - 1}) {
        for (int j : {H, H + W - 1}) {
            edges[i].push_back(j);
            edges[j].push_back(i);
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char ch;
            cin >> ch;
            if (ch == '#') {
                edges[i].push_back(j + H);
                edges[j + H].push_back(i);
            }
        }
    }
    int ans = int(1e9);
    // row
    int rcnt = 0;
    for (int i = 0; i < H; i++) {
        if (!vis[i]) {
            dfs(i);
            rcnt++;
        }
    }
    // cow
    fill(vis.begin(), vis.end(), 0);
    int ccnt = 0;
    for (int i = H; i < H + W - 1; i++) {
        if (!vis[i]) {
            dfs(i);
            ccnt++;
        }
    }
    ans = min(rcnt - 1, ccnt - 1);
    cout << ans << endl;
}
