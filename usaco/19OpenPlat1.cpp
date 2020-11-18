#include <iostream>
#include <algorithm>
#include <vector>
#include "grader.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)1e5 + 1;
int N, Q;
vector<int> edges[MAXN];
int mat[MAXN][MAXN], fa[MAXN][17], depth[MAXN];
pii pos[MAXN];

void addRoad(int a, int b){
    a++, b++;
    edges[a].push_back(b);
    edges[b].push_back(a);
}

pii build(int u, int prev, int x, int y, int dep) {
    fa[u][0] = prev;

    if (edges[u].size() == 1 && u != prev) {
        mat[x][y] = u;
        setFarmLocation(u - 1, x, y);
        pos[u] = make_pair(x, y);
        return make_pair(1, 1);
    }

    int x_ = x, y_ = y;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        pii rect = build(v, u, x, y, dep + 1);
        x += rect.first, y += rect.second;
    }
    if (mat[x - 1][y] > 0) // only 1 child
        x++;
    mat[x - 1][y_] = u;
    setFarmLocation(u - 1, x - 1, y_);
    pos[u] = make_pair(x - 1, y_);
    return make_pair(x - x_, y - y_);
}

void buildFarms() {
    N = getN(), Q = getQ();
    build(1, 1, 1, 1, 0);
    // preprocess lca
    for (int k = 1; k <= 16; k++)
        for (int i = 1; i <= N; i++)
            fa[i][k] = fa[fa[i][k - 1]][k - 1];
}

pii lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    int a_ = a;
    for (int k = 16; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    for (int k = 16; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    if (a != b)
        a = fa[a][0], b = fa[b][0];
    for (int k = 16; k >= 0; k--)
        if (depth[fa[a_][k]] < depth[a])
            a_ = fa[a_][k];
    return make_pair(a, a_);
}

void notifyFJ(int a, int b){
    pii p = lca(a, b);
    int c = p.first, d = p.second;
    if (c == a || c == b)
        addBox(pos[a].first, pos[a].second, pos[b].first, pos[b].second);
    else {
        addBox(pos[a].first, pos[a].second, pos[d].first, pos[d].second);
        addBox(pos[b].first, pos[b].second, pos[c].first, pos[c].second);
    }
}