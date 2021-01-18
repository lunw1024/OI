#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

struct dsu {
    int fa[1001] = {0};
    int cnt, sccs;
    dsu(int n) {
        cnt = n;
        sccs = n;
        for (int i = 1; i <= cnt; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            fa[a] = b;
            sccs--;
        }
    }
};

struct Edge {
    int x, y;
    double d;
    Edge(int x, int y, double d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};

bool comp(Edge a, Edge b) {
    return a.d < b.d;
}

int N;
vector<Edge> edges;
vector<pair<int, int>> points;

int main() {
    cin >> N;
    dsu s(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < i; j++) {
            int jx = points[j].first, jy = points[j].second;
            double d = sqrt((ll)(x - jx) * (x - jx) + (ll)(y - jy) * (y - jy));
            edges.push_back(Edge(j, i, d));
        }
        points.push_back(make_pair(x, y));
    }
    sort(edges.begin(), edges.end(), comp);
    for (Edge e : edges) {
        s.merge(e.x, e.y);
        if (s.sccs == 1) {
            cout << setprecision(8) << e.d / 2 << endl;
            break;
        }
    }
}