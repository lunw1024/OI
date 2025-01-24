#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const ll INF = static_cast<ll>(1e17);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        // cerr << "case " << t << endl;
        int n, m, v;
        cin >> n >> m >> v;
        ll total = 0;
        vi arr(n + 2), pre(n + 2), suf(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            total += arr[i];
        }
        int l = 0, r = 0;
        int s = 0;
        for (; r <= n; r++) {
            s += arr[r];
            // cerr << "before, " << l << ", " << r << ", s = " << s << endl;
            while (l < r && s >= v + arr[l + 1]) {
                s -= arr[l + 1];
                l++;
            }
            // cerr << l << ", " << r << ", s = " << s << endl;
            pre[r] = pre[l] + (s >= v);
            // cerr << "pre[" << r << "] = " << pre[r] << endl;
        }
        l = n + 1, r = n + 1;
        s = 0;
        for (; l >= 1; l--) {
            s += arr[l];
            while (r > l && s >= v + arr[r - 1]) {
                s -= arr[r - 1];
                r--;
            }
            suf[l] = suf[r] + (s >= v);
        }

        vector<ll> left(m + 1, INF), right(m + 1, INF);
        ll cost = 0;
        for (int i = 0; i <= n; i++) {
            cost += arr[i];
            int cnt = min(m, pre[i]);
            left[cnt] = min(left[cnt], cost);
        }
        cost = 0;
        for (int i = n + 1; i >= 1; i--) {
            cost += arr[i];
            int cnt = min(suf[i], m);
            right[cnt] = min(right[cnt], cost);
        }
        ll ans = -1;
        for (int i = 0; i <= m; i++) {
            ans = max(ans, total - left[i] - right[m - i]);
        }
        cout << ans << endl;
    }
}

