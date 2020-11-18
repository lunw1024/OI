#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

struct Edge {
    int to, res;
    Edge(int to, int res) {
        this->to = to;
        this->res = res;
    }
};

const int MAXN = 102, INF = 2147483647;
int N, M, S, T;
vector<Edge> edges;
vector<int> E[MAXN];
int depth[MAXN], cur[MAXN];
bool vis[MAXN];
int last[1001], pigs[1001];

bool dinic_bfs() {
    fill(vis, vis + 2 + N, false);
    queue<int> que;
    depth[S] = 0;
    vis[S] = true;
    que.push(S);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i : E[u]) {
            int v = edges[i].to;
            if (!vis[v] && edges[i].res > 0) {
                vis[v] = true;
                depth[v] = depth[u] + 1;
                que.push(v);
            }
        }
    }
    return vis[T];
}

int dinic_dfs(int u, int flow) {
    if (u == T)
        return flow;
    int out = 0;
    for (int& i = cur[u]; i < E[u].size() && flow > 0; i++) {
        int v = edges[E[u][i]].to;
        if (depth[v] == depth[u] + 1 && edges[E[u][i]].res > 0) {
            int f = dinic_dfs(v, min(flow, edges[E[u][i]].res));
            edges[E[u][i]].res -= f;
            edges[E[u][i] ^ 1].res += f;
            flow -= f;
            out += f;
        }
    }
    return out;
}

int maxflow() {
    int flow = 0;
    while (dinic_bfs()) {
        fill(cur, cur + 2 + N, 0);
        flow += dinic_dfs(S, INF);
    }
    return flow;
}

void add_edge(int from, int to, int res) {
    E[from].push_back(edges.size());
    edges.push_back(Edge(to, res));
    E[to].push_back(edges.size());
    edges.push_back(Edge(from, 0));
}

int main() {
    cin >> M >> N;
    S = 0, T = N + 1;

    for (int i = 1; i <= M; i++)
        cin >> pigs[i];

    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A;
        for (int j = 0; j < A; j++) {
            int pig;
            cin >> pig;
            if (last[pig] > 0) {
                add_edge(last[pig], i, INF);
            } else {
                add_edge(S, i, pigs[pig]);
            }
            last[pig] = i;
        }
        cin >> B;
        add_edge(i, T, B);
    }

    cout << maxflow() << endl;
}