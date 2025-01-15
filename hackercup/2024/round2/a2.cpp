#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int ans = 0;
ll a, b, m;

void dfs(ll x, int d, int k) {
    // x is the prefix, k is # digits on each size of middle
    int last = x % 10;
    // cerr << x << endl;
    if (d == k) {
        for (int i = last + 1; i <= 9; i++) {
            dfs(x * 10 + i, d + 1, k);
        }
    } else if (d < k) {
        for (int i = last; i <= 8; i++) {
            if (i == 0) {
                continue;
            }
            // cerr << "+" << last << endl;
            dfs(x * 10 + i, d + 1, k);
        }
    } else if (d < 2 * k + 1) {
        for (int i = last; i >= 1; i--) {
            if (i == last && d == k + 1) {
                continue;
            }
            dfs(x * 10 + i, d + 1, k);
        }
    } else if (d == 2 * k + 1) {
        if (a <= x && x <= b && x % m == 0) {
            // cerr << x << endl;
            ans++;
        }
    }
}


int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> a >> b >> m;
        ans = 0;
        for (int k = 0; k <= 8; k++) {
            dfs(0, 0, k);
        }
        cerr << "Running case " << t << " / " << T << endl;
        cout << "Case #" << t << ": " << ans << endl;
    }
}
