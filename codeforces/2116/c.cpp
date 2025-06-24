#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;

    // vector<int, vector<int>> gcd(5000, )
    
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int global = a[0];
        for (int i = 1; i < n; i++) {
            global = gcd(global, a[i]);
        }
        bool ok = false;
        for (int x : a) {
            if (x == global) {
                ok = true;
                break;
            }
        }
        if (ok) {
            int ans = n;
            for (int x : a) {
                ans -= x == global;
            }
            cout << ans << endl;
            continue;
        }
        
        vi dp(5001, n);
        for (int x : a) {
            dp[x] = 0;
            for (int i = 2; i < dp.size(); i++) {
                int g = gcd(i, x);
                // cerr << "gcd(" << i << ", " << x << ") = " << g << endl;
                dp[g] = min(dp[g], dp[i] + 1);
            }
        }
        // cerr << dp[global] << "," << endl;
        int ans = dp[global] + n - 1;
        cout << ans << endl;
    }
}

