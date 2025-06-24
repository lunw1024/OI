#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vi p(n), q(n);
        vector<pii> mp(n), mq(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (i > 0) {
                if (p[i] > mp[i - 1].second) {
                    mp[i] = {i, p[i]};
                } else {
                    mp[i] = mp[i - 1];
                }
            } else {
                mp[i] = {0, p[0]};
            }
            // cerr << mp[i].first << ", " << mp[i].second << endl;
        }
        for (int i = 0; i < n; i++) {
            cin >> q[i];
            if (i > 0) {
                if (q[i] > mq[i - 1].second) {
                    mq[i] = {i, q[i]};
                } else {
                    mq[i] = mq[i - 1];
                }
            } else {
                mq[i] = {0, q[0]};
            }

            // cerr << mq[i].first << ", " << mq[i].second << endl;
        }
        vi powmod(n);
        powmod[0] = 1;
        for (int i = 1; i < n; i++) {
            powmod[i] = (powmod[i - 1] << 1) % MOD;
        }
        for (int i = 0; i < n; i++) {
            pii a = {mp[i].second, q[i - mp[i].first]};
            pii b = {mq[i].second, p[i - mq[i].first]};
            pii ord = max(a, b);
            int ans = (powmod[ord.first] + powmod[ord.second]) % MOD;
            cout << ans << " ";
        }
        cout << endl;
    }
}

