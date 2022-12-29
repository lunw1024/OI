#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
const int MOD = int(1e9) + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    // sum n^2 + sum n(n+1) = (sum 2n^2 + n) + n^2
    int T;
    ll ans = 0;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll n;
        cin >> n;
        ans = ((2 * (n-1)*(n) % MOD *(2*n-1) % MOD + n * (n - 1) *3 + n*n * 6) % MOD) * 337 % MOD;
        cout << ans << endl;
    }
}
