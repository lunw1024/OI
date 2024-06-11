#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> a(n), b(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n + 1; i++) {
            cin >> b[i];
        }
        int x = b[n];
        ll ans = 0;
        int extra = int(1e9);
        for (int i = 0; i < n; i++) {
            ans += abs(a[i] - b[i]);
            if (a[i] <= x && x <= b[i] || b[i] <= x && x <= a[i]) {
                extra = 0;
            } else {
                extra = min(extra, min(abs(a[i] - x), abs(b[i] - x)));
            }
        }
        ans += extra + 1;
        cout << ans << endl;
    }
}
