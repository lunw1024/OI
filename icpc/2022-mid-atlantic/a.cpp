#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ll h, k, v, s;
    cin >> h >> k >> v >> s;
    ll ans = 0;
    while (h > 0) {
        v += s;
        v -= max(1ll, v / 10);
        if (v >= k) {
            h++;
        } else {
            h--;
            if (h == 0) {
                v = 0;
            }
        }
        if (v <= 0) {
            h = 0;
            v = 0;
        }
        ans += v;
        if (s > 0) {
            s--;
        }
    }
    cout << ans << endl;
}
