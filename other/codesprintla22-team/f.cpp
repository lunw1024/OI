#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
using namespace std;


const int INF = int(1e9);

struct Edge {
    int a, b, c, f;
    Edge(int a, int b, int c, int f) : a(a), b(b), c(c), f(f) {}
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<vector<int>> G; // adjacency list
    vector<int> d, cur;

    Dinic(int n) : n(n) {
        G.resize(n); d.resize(n); cur.resize(n);
    }

    void addEdge(int a, int b, int c) {
        edges.push_back(Edge(a, b, c, 0));
        edges.push_back(Edge(b, a, 0, 0));
        m = edges.size();
        G[a].push_back(m - 2);
        G[b].push_back(m - 1);
    }

    bool bfs() {
        fill(d.begin(), d.end(), INF);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : G[u]) {
                Edge e = edges[i];
                if (d[e.b] == INF && e.c > e.f) {
                    d[e.b] = d[e.a] + 1;
                    q.push(e.b);
                }
            }
        }
        return d[t] != INF;
    }

    int dfs(int u, int a) {
        if (u == t || a == 0)
            return a;
        int f, total = 0;
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

    int maxflow(int s, int t) {
        this->s = s;
        this->t = t;
        int ans = 0;
        while (bfs()) {
            fill(cur.begin(), cur.end(), 0);
            ans += dfs(s, INF);
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Dinic dinic = Dinic(m * 2 + 2);
    set<pair<int, int>> pokemon;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pokemon.insert(make_pair(x + 1, y + 1));
    }
    for (pair<int, int> p : pokemon) {
        cerr << p.first << ", " << p.second << endl;
        dinic.addEdge(p.first, p.second + m, 1);
    }
    for (int i = 1; i <= m; i++) {
        dinic.addEdge(0, i, 1);
        dinic.addEdge(i + m, m * 2 + 1, 1);
    }
    int maxflow = dinic.maxflow(0, m * 2 + 1);
    cout << maxflow << endl;
}

