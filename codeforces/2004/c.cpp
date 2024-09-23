#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        int n, k;
        cin >> n >> k;
        ll diff = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n - n % 2; i++) {
            ll sign = i % 2 == 0 ? 1 : -1;
            ll x = a[n - 1 - i];
            diff += sign * x;
        }
        cout << max(0ll, diff - k) + (n % 2 == 1 ? a[0] : 0) << endl;
    }
}
