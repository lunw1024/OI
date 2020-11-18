#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

struct Edge {
    int to, res, rev;
    Edge(int to, int res, int rev) {
        this->to = to;
        this->res = res;
        this->rev = rev;
    }
};

const int MAXN = 55002, INF = 2147483647;
int N, M, S, T;
vector<Edge> edges[MAXN];
int depth[MAXN], cur[MAXN];
bool vis[MAXN];

bool dinic_bfs() {
    fill(vis, vis + 2 + N + M, false);
    queue<int> que;
    que.push(S);
    depth[S] = 0;
    vis[S] = true;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (Edge e : edges[u]) {
            if (!vis[e.to] && e.res > 0) {
                vis[e.to] = true;
                depth[e.to] = depth[u] + 1;
                que.push(e.to);
            }
        }
    }
    return vis[T];
}

int dinic_dfs(int u, int flow) {
    if (u == T)
        return flow;
    int out = 0;
    for (int& i = cur[u]; i < edges[u].size() && flow > 0; i++) {
        Edge e = edges[u][i];
        if (depth[e.to] == depth[u] + 1 && e.res > 0) {
            int f = dinic_dfs(e.to, min(flow, e.res));
            edges[u][i].res -= f;
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
        fill(cur, cur + 2 + N + M, 0);
        flow += dinic_dfs(S, INF);
    }
    return flow;
}

int main() {
    cin >> N >> M;
    S = 0, T = N + M + 1;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int cap;
        cin >> cap;
        edges[i].push_back(Edge(N + M + 1, cap, edges[N + M + 1].size()));
        edges[N + M + 1].push_back(Edge(i, 0, edges[i].size() - 1));
    }
    for (int i = N + 1; i <= N + M; i++) {
        int a, b, cap;
        cin >> a >> b >> cap;
        sum += cap;
        edges[0].push_back(Edge(i, cap, edges[i].size()));
        edges[i].push_back(Edge(0, 0, edges[0].size() - 1));
        edges[i].push_back(Edge(a, INF, edges[a].size()));
        edges[a].push_back(Edge(i, 0, edges[i].size() - 1));
        edges[i].push_back(Edge(b, INF, edges[b].size()));
        edges[b].push_back(Edge(i, 0, edges[i].size() - 1));
    }

    cout << sum - maxflow() << endl;
}