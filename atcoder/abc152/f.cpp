#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = (int)1e9 + 7;
int N, M, pow2[50];
ll ans = 0;
vector<int> edges[50];
vector<P> constraints[20];

void dfs(int u, int prev, int target, vector<P>& out) {
    if (u == target) {
        if (u == prev)
            return;
        if (u > prev)
            swap(u, prev);
        out.push_back(make_pair(u, prev));
        return;
    }
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        dfs(v, u, target, out);
        if (!out.empty()) {
            if (u == prev)
                return;
            if (u > prev)
                swap(u, prev);
            out.push_back(make_pair(u, prev));
            return;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dfs(u, u, v, constraints[i]);
    }

    pow2[0] = 1;
    for (int i = 1; i < N; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    
    for (int s = 0; s < (1 << M); s++) {
        set<P> st;
        for (int i = 0; i < M; i++) {
            if (s >> i & 1) {
                for (P e : constraints[i])
                    st.insert(e);
            }
        }
        int k = 0;
        for (int x = s; x > 0; x >>= 1)
            k += x & 1;
        int size = st.size();
        ans += pow2[N - size - 1] * (1 - k % 2 * 2);
        ans = (ans % MOD + MOD) % MOD;
    }
    cout << ans << endl;
}