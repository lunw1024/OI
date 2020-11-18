#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)1e5 + 1;
int N, MOD;

struct SegmentTree {
    ll v[MAXN * 4 + 1];

    inline int ls(int x) {
        return x << 1;
    }

    inline int rs(int x) {
        return x << 1 | 1;
    }

    void build(int x, int l, int r) {
        // v[x] = 1;
        // if (l == r)
        //     return;
        // int mid = (l + r) / 2;
        // build(ls(x), l, mid);
        // build(rs(x), mid + 1, r);
        fill(v, v + 4 * N, 1);
    }

    void update(int x, int l, int r, int target, ll val) {
        if (l == r) {
            v[x] = val % MOD;
            return;
        }
        int mid = (l + r) / 2;
        if (target <= mid)
            update(ls(x), l, mid, target, val);
        else
            update(rs(x), mid + 1, r, target, val);
        v[x] = v[ls(x)] * v[rs(x)] % MOD;
    }
};

SegmentTree tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> MOD;
        tree.build(1, 1, N);
        for (int i = 1; i <= N; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                ll val;
                cin >> val;
                tree.update(1, 1, N, i, val);
                cout << tree.v[1] << endl;
            } else {
                int target;
                cin >> target;
                tree.update(1, 1, N, target, 1);
                cout << tree.v[1] << endl;
            }
        }
    }
}
