#include <iostream>
using namespace std;

const int MOD = 998244353;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        ll W, G, L;
        cin >> W >> G >> L;
        ll ans = (1 + 2 * L) % MOD;
        ans = ans * ((W - G) % MOD) % MOD;
        cout << "Case #" << task << ": " << ans << endl;
    }
}
