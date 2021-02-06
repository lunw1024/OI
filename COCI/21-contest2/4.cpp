#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct dsu {
    vector<int> fa;
    vector<ll> mx;
    int cnt;
    dsu(int n) {
        cnt = n;
        for (int i = 0; i < cnt; i++) {
            fa.push_back(i);
            mx.push_back(0ll);
        }
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    ll merge(int a, int b) {
        a = find(a);
        b = find(b);
        ll ret = mx[a] + mx[b];
        fa[a] = b;
        mx[b] = max(mx[a], mx[b]);
        return ret;
    }
};

struct Edge {
    int a, b;
    ll w;
    Edge(int a, int b, ll w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool comp(Edge a, Edge b) {
    return a.w < b.w;
}

int N;
vector<int> hard;
vector<Edge> edges;

int main() {
    cin >> N;
    dsu s(N);
    for (int i = 0; i < N; i++) {
        cin >> s.mx[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ll w = max(s.mx[a], s.mx[b]);
        edges.push_back(Edge(a, b, w));
    }
    sort(edges.begin(), edges.end(), comp);
    ll ans = 0;
    for (Edge e : edges) {
        ll temp = s.merge(e.a, e.b);
        ans += temp;
    }
    cout << ans << endl;
}