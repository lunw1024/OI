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
    vector<ll> a(n);
    ll sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    ll ans = 0;
    if (mx >= 2 * (sum - mx)) {
        ans = (sum - mx);
    } else {
        ans = sum / 3;
    }
    cout << ans << endl;
}

