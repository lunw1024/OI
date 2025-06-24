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
    ll premin = 0;
    ll pre = 0;
    ll ans = -ll(1e18);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pre += x;
        ans = max(ans, pre - premin);
        premin = min(premin, pre);
    }
    cout << ans << endl;
}

