#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Node {
    int v = 0;
    int ls = 0, rs = 0;
    void set(int v, int ls, int rs) {
        this->v = v;
        this->ls = ls;
        this->rs = rs;
    }
} nodes[(int)34e5];

const int MAXN = (int)1e5 + 1;
ll INF = (ll)1e10;
int N, L, R, top = 1;

void add(int idx, ll l, ll r, int x) {
    ll mid = (l + r) / 2;
    Node& u = nodes[idx];
    if (l == r) {
        u.v++;
        return;
    }
    if (x <= mid) {
        add(u.ls == 0 ? (u.ls = top++) : u.ls, l, mid, x);
    } else {
        add(u.rs == 0 ? (u.rs = top++) : u.rs, mid + 1, r, x);
    }
    u.v = nodes[u.ls].v + nodes[u.rs].v;
}

int sum(int idx, ll l, ll r, int ql, int qr) {
    if (qr < l || r < ql)
        return 0;
    ll mid = (l + r) / 2;
    Node& u = nodes[idx];
    if (ql <= l && r <= qr)
        return u.v;
    return sum(u.ls, l, mid, ql, qr) + sum(u.rs, mid + 1, r, ql, qr);
}


int main() {
    ll ans = 0, pre = INF;
    cin >> N >> L >> R;
    add(1, 0, 2 * INF, INF);
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        pre += x;
        int temp = sum(1, 0, 2 * INF, pre - R, pre - L);
        ans += temp;
        add(1, 0, 2 * INF, pre);
    }
    cout << ans << endl;
}