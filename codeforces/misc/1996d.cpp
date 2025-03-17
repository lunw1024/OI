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
        ll n, x, ans = 0;
        cin >> n >> x;
        for (int a = 1; a < min(n, x); a++) {
            for (int b = 1; b < n / a; b++) {
                ans += max(0ll, min(x - a - b, (n - a * b) / (a + b)));
                // cout << "a = " << a << ", b = " << b << endl;
                // cout << "ans = " << ans << endl;
            }
        }
        cout << ans << endl;
    }
}

