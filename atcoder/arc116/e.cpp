// tree dp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector<vector<int>> edges;

int dfs(int u, int prev, int r, int& num) {
    int dist = r + 1;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        int d = dfs(v, u, r, num) + 1;
        if (dist + d <= 2 * r + 1) { // can cover all
            dist = min(dist, d); // nearest source
        } else { // can't cover all
            dist = max(dist, d); // deepest uncovered node
        }
    }
    if (dist >= 2 * r + 1) {
        num++;
        dist = 0;
    }
    if (u == prev && dist > r)
        num++;
    // cerr << "at node " << u << " dist = " << dist << endl;
    return dist;
}

bool check(int r) {
    int num = 0;
    dfs(1, 1, r, num);
    return num <= K;
}

int main() {
    cin >> N >> K;
    edges.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int l = 0, r = N - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        // cerr << "--- searching " << mid << " ---" << endl;
        if (check(mid)) {
            // cerr << "ok" << endl;
            r = mid - 1;
        } else {
            // cerr << "no" << endl;
            l = mid + 1;
        }
    }
    cout << l << endl;
}