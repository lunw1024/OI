// https://www.luogu.com.cn/problem/P7165
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using pii = pair<int, int>;

const int MAXN = (int)2e5;
int N;
vector<int> edges[MAXN + 1];
vector<int> sz(MAXN + 1);
multiset<int> A, B;

int dfs(int u, int fa) {
    int res = 1;
    for (int v : edges[u]) {
        if (v == fa)
            continue;
        res += dfs(v, u);
    }
    sz[u] = res;
    return res;
}

void solve(int u, int fa) {
    A.insert(sz[u]);
    for (int v : edges[fa]) {
        if (v == fa)
            continue;
        solve(v, u);
    }
    
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 1);
    
    solve(1, 1);
}
