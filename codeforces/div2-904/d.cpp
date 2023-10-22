#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        ll ans = 1ll * N * (N - 1) / 2;
        vector<int> vis(N + 1);
        vector<int> cnt(N + 1);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int i = 1; i <= N; i++) {
            ll sum = 0;
            if (vis[i] > 0 || cnt[i] == 0) {
                continue;
            }
            // ll sign = (vis[i] % 2) * 2 - 1;
            for (int j = i; j <= N; j += i) {
                sum += cnt[j];
                vis[j]++;
            }
            // cerr << "+= " << -sum * (sum - 1) / 2 << endl;
            ans -= sum * (sum - 1) / 2;
        }
        for (int i = 1; i <= N; i++) {
            ll sum = 0;
            int mul = vis[i];
            if (mul >= 2) {
                // ll sign = 1 - (vis[i] % 2) * 2;
                // cerr << i << ", sign = " << sign << endl;
                for (int j = i; j <= N; j += i) {
                    sum += cnt[j];
                    vis[j] -= mul - 1;
                }
                // cerr << "+= " << sign * sum * (sum - 1) / 2 << endl;
                ans += 1ll * sum * (sum - 1) / 2 * (mul - 1);
            } else if (cnt[i] > 0 && mul <= 0) {
                // ll sign = 1 - (vis[i] % 2) * 2;
                // cerr << i << ", sign = " << sign << endl;
                for (int j = i; j <= N; j += i) {
                    sum += cnt[j];
                    vis[j] += 1 - mul;
                }
                // cerr << "+= " << sign * sum * (sum - 1) / 2 << endl;
                ans -= 1ll * sum * (sum - 1) / 2 * (1 - mul);
            }
        }
        cout << ans << endl;
    }
}