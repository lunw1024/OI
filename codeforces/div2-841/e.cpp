#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll M;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        vector<ll> cnt(N + 1);
        for (int i = N; i >= 2; i--) {
            cnt[i] = ll(N / i) * (ll(N / i) - 1) / 2;
            for (int j = 2; j <= int(N / i); j++) {
                cnt[i] -= cnt[j * i];
            }
        }
        ll ans = 0;
        for (int i = N; i >= 2; i--) {
            ll k = min(M / (i - 1), cnt[i] / (i - 1));
            M -= k * (i - 1);
            ans += i * k;
        }
        cout << (M == 0 ? ans : -1) << endl;
    }
}
