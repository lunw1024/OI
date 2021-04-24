#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<vector<int>> edges;
vector<bool> ondiameter;
vector<int> ans;

pii far(int u, int prev, int d) {
    int node = u, dis = 0;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        pii temp = far(v, u, d + 1);
        if (dis < temp.second + 1) {
            dis = temp.second + 1;
            node = temp.first;
        }
    }
    return make_pair(node, dis);
}

bool tag(int u, int prev, int target) {
    if (u == target)
        return true;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        if (tag(v, u, target)) {
            ondiameter[u] = true;
            return true;
        }
    }
    return false;
}

int t = 1;
void solve(int u, int prev) {
    ans[u] = t;
    for (int v : edges[u]) {
        if (v == prev || ondiameter[v])
            continue;
        t++;
        solve(v, u);
    }
    for (int v : edges[u]) {
        if (v != prev && ondiameter[v]) {
            t++;
            solve(v, u);
        }
    }
    t++;
}

int main() {
    cin >> N;
    ondiameter.resize(N + 1);
    edges.resize(N + 1);
    ans.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    // find diameter
    pii a = far(1, 1, 0);
    pii b = far(a.first, a.first, 0);
    tag(a.first, a.first, b.first);
    solve(a.first, a.first);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}