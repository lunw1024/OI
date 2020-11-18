#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = (int)1e5;
string s;

struct Element {
    int cnt[26];

    Element() {
        fill(cnt, cnt + 26, 0);
    }

    Element operator+(const Element& o) const {
        Element out;
        for (int i = 0; i < 26; i++)
            out.cnt[i] = this->cnt[i] + o.cnt[i];
        return out;
    }

    void clear() {
        fill(cnt, cnt + 26, 0);
    }
};

struct SegTree {
    Element data[MAXN * 4];
    int tag[MAXN * 4];

    inline int ls(int x) {
        return x << 1;
    }
    
    inline int rs(int x) {
        return x << 1 | 1;
    }

    void build(int x, int l, int r) {
        if (l == r) {
            data[x].cnt[s[l] - 'a'] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(ls(x), l, mid);
        build(rs(x), mid + 1, r);
        data[x] = data[ls(x)] + data[rs(x)];
    }

    void pushdown(int x, int l, int r) {
        // cout << tag[3] << endl;
        if (l == r || tag[x] == 0)
            return;
        int mid = (l + r) / 2;
        data[ls(x)].clear();
        data[ls(x)].cnt[tag[x] - 1] = mid - l + 1;
        tag[ls(x)] = tag[x];
        data[rs(x)].clear();
        data[rs(x)].cnt[tag[x] - 1] = r - mid;
        tag[rs(x)] = tag[x];
        tag[x] = 0;
    }

    Element query(int x, int l, int r, int s, int t) {
        pushdown(x, l, r);
        if (r < s || t < l) {
            return Element();
        }
        if (s <= l && r <= t) {
            return data[x];
        }
        int mid = (l + r) / 2;
        return query(ls(x), l, mid, s, t) + query(rs(x), mid + 1, r, s, t);
    }

    void update(int x, int l, int r, int s, int t, int v) {
        pushdown(x, l, r);
        if (r < s || t < l)
            return;
        if (s <= l && r <= t) {
            data[x].clear();
            data[x].cnt[v] = r - l + 1;
            tag[x] = v + 1;
            return;
        }
        int mid = (l + r) / 2;
        update(ls(x), l, mid, s, t, v);
        update(rs(x), mid + 1, r, s, t, v);
        data[x] = data[ls(x)] + data[rs(x)];
    }
};

int N, M;
SegTree tree;

int main() {
    cin >> N >> M >> s;
    tree.build(1, 0, N - 1);
    
    for (int i = 0; i < M; i++) {
        int x, l, r;
        cin >> l >> r >> x;
        l--, r--;
        Element sum = tree.query(1, 0, N - 1, l, r);
        if (x == 1) {
            for (int c = 0; c < 26; c++) {
                if (sum.cnt[c] == 0)
                    continue;
                tree.update(1, 0, N - 1, l, l + sum.cnt[c] - 1, c);
                l += sum.cnt[c];
            }
        } else {
            for (int c = 25; c >= 0; c--) {
                if (sum.cnt[c] == 0)
                    continue;
                tree.update(1, 0, N - 1, l, l + sum.cnt[c] - 1, c);
                l += sum.cnt[c];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        Element ele = tree.query(1, 0, N - 1, i, i);
        for (int j = 0; j < 26; j++)
            if (ele.cnt[j] > 0)
                cout << (char)('a' + j);
    }
    cout << endl;
}