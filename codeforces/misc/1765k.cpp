#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    ll mindiag = ll(1e9);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll x;
            cin >> x;
            if (i + j == n - 1) {
                mindiag = min(mindiag, x);
            }
            ans += x;
        }
    }
    ans -= mindiag;
    cout << ans << endl;
}

