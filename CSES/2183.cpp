#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    long long l = 0, r = 1;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int x : a) {
        long long ll = l + x, rr = r + x;
        if (ll <= r) {
            r = rr;
        } else {
            ans = r;
        }
    }
    ans = r;
    cout << ans << endl;
}

