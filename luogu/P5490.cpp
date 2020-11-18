#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)8e5 + 5;
int N;
vector<ll> values;
ll ans = 0;

struct SegmentTree {
    int s[MAXN], t[MAXN], cnt[MAXN];
    ll len[MAXN];

    inline int ls(int x) {
        return x << 1;
    }

    inline int rs(int x) {
        return x << 1 | 1;
    }

    void build(int x, int l, int r) {
        s[x] = l, t[x] = r, cnt[x] = 0, len[x] = 0;
        if (r - l <= 1)
            return;
        int mid = (l + r) / 2;
        build(ls(x), l, mid);
        build(rs(x), mid, r);
    }

    void pushup(int x) {
        if (cnt[x] > 0) {
            len[x] = values[t[x]] - values[s[x]];
        } else if (t[x] - s[x] > 1) {
            len[x] = len[ls(x)] + len[rs(x)];
        } else {
            len[x] = 0;
        }
    }

    void update(int x, int l, int r, int v) {
        if (r <= s[x] || t[x] <= l)
            return;
        if (l <= s[x] && t[x] <= r) {
            cnt[x] += v;
            pushup(x);
            return;
        }
        update(ls(x), l, r, v);
        update(rs(x), l, r, v);
        pushup(x);
    }
} tree;

struct Line {
    ll x, y1, y2;
    int v;
    Line(ll x, ll y1, ll y2, int v) {
        this->x = x;
        this->y1 = y1;
        this->y2 = y2;
        this->v = v;
    }
};

bool comp(Line a, Line b) {
    return a.x < b.x;
}

vector<Line> lines;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back(Line(x1, y1, y2, 1));
        lines.push_back(Line(x2, y1, y2, -1));
        values.push_back(y1);
        values.push_back(y2);
    }

    sort(lines.begin(), lines.end(), comp);
    sort(values.begin(), values.end());
    vector<ll>::iterator it = unique(values.begin(), values.end());
    values.erase(it, values.end());

    tree.build(1, 0, values.size() - 1);
    ll prev = lines[0].x;
    for (Line line : lines) {
        ans += (line.x - prev) * tree.len[1];
        int l = lower_bound(values.begin(), values.end(), line.y1) - values.begin();
        int r = lower_bound(values.begin(), values.end(), line.y2) - values.begin();
        tree.update(1, l, r, line.v);
        prev = line.x;
    }

    cout << ans << endl;
}