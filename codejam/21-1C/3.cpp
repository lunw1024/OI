#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = int(1e9), MAXN = 1 << 20;
string s, e;
vector<int> dist;

int to_int(string x) {
    int out = 0, a = 1;
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] == '1')
            out += a;
        a <<= 1;
    }
    return out;
}

int flip(int x) {
    if (x == 0)
        return 1;
    int a = 1;
    while (x >= a) {
        x ^= a;
        a <<= 1;
    }
    return x;
}

int bfs(string s, string e) {
    queue<int> q;
    int a = to_int(s), b = to_int(e);
    dist[a] = 0;
    q.push(a);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if ((u << 1) < MAXN && dist[u << 1] == INF) {
            dist[u << 1] = dist[u] + 1;
            q.push(u << 1);
        }
        if (dist[flip(u)] == INF) {
            dist[flip(u)] = dist[u] + 1;
            q.push(flip(u));
        }
        if (dist[b] != INF)
            return dist[b];
    }
    return dist[b];
}

int main() {
    int T;
    cin >> T;


    for (int t = 1; t <= T; t++) {
        cin >> s >> e;
        dist.clear();
        dist.resize(MAXN, INF);
        int ans = bfs(s, e);
        cout << "Case #" << t << ": " << (ans == INF ? "IMPOSSIBLE" : to_string(ans)) << endl;
    }
}