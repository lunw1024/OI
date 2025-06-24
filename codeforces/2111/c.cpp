#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vi cnt(n + 1);
        int count = 0;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (prev != x) {
                count = 1;
                prev = x;
            } else {
                count++;
            }
            cnt[x] = max(cnt[x], count);
        }
        ll ans = ll(1e18);
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                continue;
            }
            ans = min(ans, ll(n - cnt[i]) * i);
        }
        cout << ans << endl;
    }
}

