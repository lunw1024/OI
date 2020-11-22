#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 50001, INF = (int)1e9;
int N, M;
vector<int> edges[MAXN];
vector<pii> allEdges;
int parent[MAXN][16], depth[MAXN], ans[MAXN];
vector<int> vec[MAXN];

void preprocess(int u, int prev, int dep) {
    parent[u][0] = prev;
    depth[u] = dep;
    for (int k = 1; k < 16; k++)
        parent[u][k] = parent[parent[u][k - 1]][k - 1];
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        preprocess(v, u, dep + 1);
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b])
        swap(a, b);
    for (int i = 15; i >= 0; i--)
        if (depth[parent[a][i]] <= depth[b])
            a = parent[a][i];
    for (int i = 15; i >= 0; i--)
        if (parent[a][i] != parent[b][i])
            a = parent[a][i], b = parent[b][i];
    return a == b ? a : parent[a][0];
}

multiset<int> st;
void dfs(int u, int prev) {
    cout << st.size() << endl;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        dfs(v, u);
    }
    ans[u] = st.empty() ? -1 : *(st.begin());
    for (int w : vec[u]) {
        if (w > 0)
            st.insert(w);
        else {
            cout << (st.find(w) == st.end()) << endl;
            st.erase(st.find(w));
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        allEdges.push_back(make_pair(a, b));
    }
    preprocess(1, 1, 0);
    for (int i = 1; i <= M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        int c = lca(a, b);
        vec[parent[c][0]].push_back(-w);
        vec[parent[c][0]].push_back(-w);
        vec[a].push_back(w);
        vec[b].push_back(w);
    }
    dfs(1, 1);
    for (pii e : allEdges) {
        cout << ans[depth[e.first] < depth[e.second] ? e.second : e.first] << endl;
    }
}