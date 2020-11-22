#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)1e5 + 5;
int N, Q;
ifstream cin("snowcow.in");
ofstream cout("snowcow.out");

struct BIT {
    ll data[MAXN];
    inline int lowbit(int x) {
        return x & -x;
    }

    void add(int x, ll k) {
        while (x <= N + 1) {
            data[x] += k;
            x += lowbit(x);
        }
    }

    ll query(int x) {
        ll out = 0;
        while (x > 0) {
            out += data[x];
            x -= lowbit(x);
        }
        return out;
    }

    ll sum(int l, int r) {
        if (r < l)
            return 0;
        return query(r) - query(l - 1);
    }
};

vector<int> edges[MAXN];
int dfn[MAXN], cnt = 1, sz[MAXN];
BIT bit1, bit2;
map<int, int> s[MAXN];

int dfs(int u, int prev) {
    dfn[u] = cnt++;
    sz[u] = 1;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

void update(int x, ll k) {
    bit1.add(dfn[x], k);
    bit1.add(dfn[x] + sz[x], -k);
    bit2.add(dfn[x], k * sz[x]);
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    dfs(1, 1);

    for (int i = 1; i <= Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, c;
            cin >> x >> c;
            map<int, int>::iterator it = s[c].upper_bound(dfn[x]);
            if (it != s[c].begin() && dfn[x] < dfn[prev(it)->second] + sz[prev(it)->second])
                continue;
            while (it != s[c].end() && it->first < dfn[x] + sz[x]) {
                update(it->second, -1);
                it = s[c].erase(it);
            }
            s[c][dfn[x]] = x;
            update(x, 1);
        } else {
            int x;
            cin >> x;
            cout << sz[x] * bit1.query(dfn[x]) + bit2.sum(dfn[x] + 1, dfn[x] + sz[x] - 1) << endl;
        }
    }
}
