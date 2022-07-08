#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        ll K;
        cin >> K;
        vector<ll> a(N);
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            sum += a[i];
        }
        ll ans = 0;
        if (K >= N) {
            ans = sum + N * K - (N + 1) * N / 2;
        } else {
            ll s = 0;
            for (int i = 0; i < K; i++)
                s += a[i];
            ll mx = s;
            for (int i = K; i < N; i++) {
                s += a[i] - a[i - K];
                mx = max(mx, s);
            }
            ans = mx + (K - 1) * K / 2;
        }
        cout << ans << endl;
    }
}
