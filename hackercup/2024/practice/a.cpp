#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        ll k;
        cin >> n >> k;
        ll best = int(1e9);
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            best = min(best, x);
        }
        ll ans = max(best, best * (2 * n - 3));
        cout << "Case #" << t << ": " << (ans <= k ? "YES" : "NO") << endl;
    }
}
