#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void dfs(int leader, int u, vi& leaders, vi& p) {
    if (leaders[u] != 0) {
        return;
    }
    leaders[u] = leader;
    dfs(leader, p[u], leaders, p);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vi p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        int cnt = 0;
        vi leaders(n + 1);
        for (int i = 1; i <= n; i++) {
            if (leaders[i] == 0) {
                cnt++;
                dfs(cnt, i, leaders, p);
            }
        }
        int ans = n - cnt + 1;
        for (int i = 1; i < n; i++) {
            if (leaders[i] == leaders[i + 1]) {
                ans -= 2;
                break;
            }
        }
        cout << ans << endl;
    }
}

