#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vi> G(n + 1);
    vi d(n + 1), f(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        if (d[i] == 1) {
            q.push({1, i});
        }
    }
    bool ans = true;
    while (!q.empty() && ans) {
        int x = q.top().first;
        int u = q.top().second;
        q.pop();
        if (x != f[u]) {
            continue;
        }
        
        for (int v : G[u]) {
            if (d[v] > 0) {
                if (f[v] >= f[u]) {
                    f[v] += f[u];
                    f[u] = 0;
                    d[u]--;
                    d[v]--;
                    // cerr << u << " -> " << v << endl;
                    if (d[v] == 1) {
                        q.push({f[v], v});
                    }
                } else {
                    // cerr << u << " has no where to go!" << endl;
                    ans = false;
                    break;
                }
            }
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}

