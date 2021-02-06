#include <atcoder/all>
#include <iostream>
using namespace atcoder;
using namespace std;
using pii = pair<int, int>;

struct Edge {
    int to = 0, c = 0, idx = 0;
    Edge(int to, int c, int idx) {
        this->to = to;
        this->c = c;
        this->idx = idx;
    }
};

const int INF = (int)1e9;
int N, M;
vector<vector<Edge>> graph;
vector<int> dist;

int dijksta(int x) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 0; i < N; i++)
        dist[i] = INF;
    q.push(make_pair(0, x));
    while (!q.empty()) {
        int u = q.top().second, d = q.top().first;
        q.pop();
        if (dist[u] < d)
            continue;
        for (Edge e : graph[u]) {
            int v = e.to, c = e.c;
            if (dist[v] > d + c) {
                dist[v] = d + c;
                q.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[x] == INF ? -1 : dist[x];
}

int main() {
    cin >> N >> M;
    graph.resize(N);
    dist.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back(Edge(b, c, i));
    }
    for (int i = 0; i < N; i++) {
        cout << dijksta(i) << endl;
    }
}