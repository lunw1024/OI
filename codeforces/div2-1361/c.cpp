#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii parts[(int)5e5 + 1];
vector<pii> edges[1 << 20];
vector<int> ans;
bool vis[(int)1 << 20];

void fill(int u) {
    vis[u] = true;
    for (pii v : edges[u])
        if (!vis[v.first])
            fill(v.first);
}

bool is_euler_graph(int mask) {
    fill(vis, vis + 1 + mask, false);
    for (int i = 0; i <= mask; i++)
        edges[i].clear();
    for (int i = 1; i <= N; i++) {
        int u = parts[i].first & mask, v = parts[i].second & mask;
        edges[u].push_back(make_pair(v, i * 2 - 1));
        edges[v].push_back(make_pair(u, i * 2 - 2));
    }
    for (int i = 0; i <= mask; i++) {
        if (edges[i].size() & 1) 
            return false;
    }
    for (int i = 0; i <= mask; i++) {
        if (edges[i].size() > 0) {
            fill(i);
            break;
        }
    }
    for (int i = 0; i <= mask; i++) {
        if (edges[i].size() > 0 && !vis[i])
            return false;
    }
    return true;
}

void dfs(int u, int prev = -1) {
    while (!edges[u].empty()) {
        int v = edges[u].back().first, idx = edges[u].back().second;
        edges[u].pop_back();
        if (vis[idx / 2])
            continue;
        vis[idx / 2] = true;
        dfs(v, idx);
    }
    if (prev != -1) {
        ans.push_back(prev);
        ans.push_back(prev ^ 1);
    }
}

void euler_loop(int mask) {
    fill(vis, vis + 1 + N, false);
    for (int i = 0; i <= mask; i++) {
        if (edges[i].size() > 0) {
            dfs(i);
            break;
        }
    }
    assert(ans.size() == N * 2);
    for (int i : ans)
        cout << i + 1 << " ";
    cout << endl;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> parts[i].first >> parts[i].second;
    }
    for (int k = 20; k >= 0; k--) {
        if (is_euler_graph((1 << k) - 1)) {
            cout << k << endl;
            euler_loop((1 << k) - 1);
            break;
        }
    }
}