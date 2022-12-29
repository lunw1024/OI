#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        // cout << "start" << endl;
        cin >> N;
        vector<ll> cnt(N * 2 + 1), a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            a[i] = a[i] ^ a[i - 1];
            cnt[a[i]] += 1;
        }
        cnt[0] += 1;
        ll ans = 0;
        // cout << 111111111 << endl;
        for (ll i = 1; i * i <= 2 * N; i++) {
            ll target = i * i;
            for (ll j = 0; j <= N * 2; j++) {
                // j ^ x = target
                // x = target ^ j
                // cerr << target << ", " << (target ^ j) << ", " << (cnt[target ^ j] * cnt[j]) << endl;
                if ((target ^ j) < 2 * N)
                    ans += cnt[target ^ j] * cnt[j];
            }
        }
        ans /= 2;
        // cout << (N * (N + 1) / 2 - ans) << endl;
        for (int j = 0; j <= N * 2; j++) {
            ans += cnt[j] * (cnt[j] - 1) / 2;
        }
        cout << (N * (N + 1) / 2 - ans) << endl;
        // cout << "end" << endl;
    }
}
