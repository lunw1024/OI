#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to, res, rev;
    Edge(int to, int res, int rev) {
        this->to = to;
        this->res = res;
        this->rev = rev;
    }
};

const int MAXN = (int)1e4 + 1, INF = 2147483647;
int N, M, S, T;
vector<Edge> edges[MAXN];
int d[MAXN], cur[MAXN];
bool vis[MAXN];

bool dinic_bfs() {
    fill(vis + 1, vis + 1 + N, false);
    queue<int> que;
    que.push(S);
    d[S] = 0;
    vis[S] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (Edge e : edges[u]) {
            if (!vis[e.to] && e.res > 0) {
                vis[e.to] = true;
                que.push(e.to);
                d[e.to] = d[u] + 1;
            }
        }
    }
    return vis[T];
}

int dinic_dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int out = 0;
    for (; cur[u] < edges[u].size() && flow > 0; cur[u]++) {
        Edge& e = edges[u][cur[u]];
        if (e.res > 0 && d[e.to] == d[u] + 1) {
            int f = dinic_dfs(e.to, min(flow, e.res));
            edges[u][cur[u]].res -= f;
            edges[e.to][e.rev].res += f;
            flow -= f;
            out += f;
        }
    }
    return out;
}

int maxflow() {
    int flow = 0;
    while (dinic_bfs()) {
        fill(cur + 1, cur + 1 + N, 0);
        flow += dinic_dfs(S, INF);
    }
    return flow;
}

int main() {
    cin >> N >> M >> S >> T;
    for (int i = 1; i <= M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(Edge(v, w, edges[v].size()));
        edges[v].push_back(Edge(u, 0, edges[u].size() - 1));
    }

    cout << maxflow() << endl;
}