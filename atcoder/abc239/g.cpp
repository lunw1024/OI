#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = ll(1e18);

struct Edge {
    int a, b;
    ll c, f;
    Edge(int a, int b, ll c, ll f) : a(a), b(b), c(c), f(f) {}
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<vector<int>> G; // adjacency list
    vector<int> d, cur;

    Dinic(int n) : n(n) {
        G.resize(n); d.resize(n); cur.resize(n);
    }

    void addEdge(int a, int b, ll c) {
        edges.push_back(Edge(a, b, c, 0));
        edges.push_back(Edge(b, a, 0, 0));
        m = edges.size();
        G[a].push_back(m - 2);
        G[b].push_back(m - 1);
    }
    
    bool bfs() {
        fill(d.begin(), d.end(), int(1e9));
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : G[u]) {
                Edge e = edges[i];
                if (d[e.b] == int(1e9) && e.c > e.f) {
                    d[e.b] = d[e.a] + 1;
                    q.push(e.b);
                }
            }
        }
        return d[t] != int(1e9);
    }

    ll dfs(int u, ll a) {
        if (u == t || a == 0)
            return a;
        ll f, total = 0;
        for (int& i = cur[u]; i < G[u].size(); i++) {
            Edge& e = edges[G[u][i]];
            if (d[u] + 1 == d[e.b] && (f = dfs(e.b, min(a, e.c - e.f))) > 0) {
                e.f += f;
                edges[G[u][i] ^ 1].f -= f;
                total += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return total;
    }

    ll maxflow(int s, int t) {
        this->s = s;
        this->t = t;
        ll ans = 0;
        while (bfs()) {
            fill(cur.begin(), cur.end(), 0);
            ans += dfs(s, INF);
        }
        return ans;
    }
};

int N, M;
vector<ll> cost;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    cost.resize(N);
    Dinic dinic(N * 2);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dinic.addEdge(a * 2 + 1, b * 2, INF);
        dinic.addEdge(b * 2 + 1, a * 2, INF);
    }
    for (int i = 0; i < N; i++) {
        ll c;
        cin >> c;
        if (i == 0 || i == N - 1) {
            c = INF;
        }
        cost[i] = c;
        dinic.addEdge(i * 2, i * 2 + 1, c);
    }
    dinic.maxflow(0, 2 * N - 1);
    ll ans = 0;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        if (dinic.d[i * 2] < int(1e9) && dinic.d[i * 2 + 1] == int(1e9)) {
            ans += cost[i];
            v.push_back(i);
        }
    }
    cout << ans << endl << v.size() << endl;
    for (int x : v) {
        cout << x + 1 << " ";
    }
    cout << endl;
}
