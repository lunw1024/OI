#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
using pli = pair<ll, int>;

const ll INF = ll(1e5), INFINF = ll(1e18);

struct Edge {
    int to;
    ll c, d;
};


int N, M;
vector<vector<Edge>> edges;
vector<ll> dist;

ll best_time(ll c, ll d, ll t) {
    ll l = t, r = INF;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if ((mid + 1) * (mid + 2) <= d) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    // cerr << "best time is " << c + d / (l + 1) + l << ", starting at " << l << endl;
    // ll l = max(t, ll(sqrt(d)));
    return c + d / (l + 1) + l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    edges.resize(N + 1);
    dist.resize(N + 1, INFINF);
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c, d;
        cin >> a >> b >> c >> d;
        edges[a].push_back({b, c, d});
        edges[b].push_back({a, c, d});
    }
    priority_queue<pli, vector<pli>, greater<pli>> que;
    que.push(make_pair(0ll, 1));
    dist[1] = 0;
    while (!que.empty()) {
        int u = que.top().second;
        ll t = que.top().first;
        que.pop();
        if (t > dist[u])
            continue;
        for (Edge e : edges[u]) {
            // cerr << "asking best time from " << u << " to " << e.to << endl;
            // cerr << e.c << " " << e.d << " " << t << endl;
            ll nt = best_time(e.c, e.d, t);
            if (nt < dist[e.to]) {
                dist[e.to] = nt;
                que.push(make_pair(nt, e.to));
            }
        }
    }
    cout << (dist[N] == INFINF ? -1 : dist[N]) << endl;
}