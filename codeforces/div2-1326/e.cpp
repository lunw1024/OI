#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)3e5 + 1;
int N, P[MAXN], Q[MAXN], pos[MAXN], ans[MAXN];

struct SegTree {
    int data[MAXN * 4], lazy[MAXN * 4];

    inline int ls(int x) {
        return x << 1;
    }

    inline int rs(int x) {
        return x << 1 | 1;
    }

    void pushdown(int x, int l, int r) {
        if (l == r)
            return;
        if (lazy > 0) {
            data[ls(x)] += lazy[x];
            data[rs(x)] += lazy[x];
            lazy[ls(x)] += lazy[x];
            lazy[rs(x)] += lazy[x];
            lazy[x] = 0;
        }
    }

    void pushup(int x, int l, int r) {
        if (l == r)
            return;
        data[x] = min(data[ls(x)], data[rs(x)]);
    }

    void update(int x, int l, int r, int s, int t, int k) {
        pushdown(x, l, r);
        if (r < s || t < l)
            return;
        if (s <= l && r <= t) {
            data[x] += k;
            lazy[x] += k;
            return;
        }
        int mid = (l + r) / 2;
        update(ls(x), l, mid, s, t, k);
        update(rs(x), mid + 1, r, s, t, k);
        pushup(x, l, r);
    }

    bool check() {
        // cout << "check " << data[1] << endl;
        return data[1] >= 0;
    }
} tree;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        pos[P[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        cin >> Q[i];
    int cur = N;
    for (int bomb = 0; bomb < N; bomb++) {
        // add bomb
        // cout << "add " << Q[bomb] << endl;
        if (bomb > 0)
            tree.update(1, 1, N, 1, Q[bomb], 1);
        // try cur-1
        while (cur >= 1 && tree.check()) {
            // cout << "sub " << pos[cur] << endl;
            tree.update(1, 1, N, 1, pos[cur--], -1);
        }
        // cout << "record " << cur + 1 << endl;
        ans[bomb] = cur + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
