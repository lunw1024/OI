#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)1e5 + 1;
int N, M, R, P, cnt = 0;
vector<int> edges[MAXN];
int hson[MAXN], depth[MAXN], size[MAXN], fa[MAXN], top[MAXN], dfn[MAXN], idx[MAXN];

int build(int u, int d) {
    depth[u] = d;
    size[u] = 1;
    for (int v : edges[u]) {
        if (v == fa[u])
            continue;
        fa[v] = u;
        size[u] += build(v, d + 1);
        if (size[hson[u]] < size[v])
            hson[u] = v;
    }
    return size[u];
}

void decompose(int u, int t) {
    top[u] = t;
    dfn[u] = cnt;
    idx[cnt] = u;
    cnt++;
    if (hson[u] == 0)
        return;
    decompose(hson[u], t);
    for (int v : edges[u]) {
        if (v == fa[u] || v == hson[u])
            continue;
        decompose(v, v);
    }
}

int tree[MAXN * 4], lazy[MAXN * 4];


int main() {
    cin >> N >> M >> R >> P;

}