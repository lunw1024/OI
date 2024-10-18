#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
const int MOD = int(1e9) + 7;
struct Sieve {
    int n;

    vector<int> cnt, primepows, smolprime;

    Sieve(int n) {
        this->n = n;
        cnt.resize(n, 0);
        smolprime.resize(n, 0);
        for (int i = 2; i < n; i++) {
            if (cnt[i] == 0) {
                for (int j = i; j < n; j += i) {
                    cnt[j]++;
                    if (smolprime[j] == 0) {
                        smolprime[j] = i;
                    }
                }
            }
            if (cnt[i] == 1) {
                primepows.push_back(i);
            }
        }
    }
};

int main() {
    Sieve sieve(int(1e6+3));
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll L, R;
        cin >> L >> R;
        int n = R - L + 1;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = L + i;
        }
        // cerr << "grundy" << endl;
        vector<int> grundy(n);
        for (int pp : sieve.primepows) {
            int r = (L - 1) % pp;
            ll x = ((L - 1) - r) + pp;
            for (; x <= R; x += pp) {
                grundy[x - L]++;
                a[x - L] /= sieve.smolprime[pp];
            }
        }
        int max_grundy = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 1) {
                grundy[i]++;
            }
            max_grundy = max(max_grundy, (2 << int(log2(grundy[i]))) - 1);
        }
        // cerr << "dp" << endl;
        vector<int> dp(max_grundy + 1, 0);
        dp[0] = 1; // g = 1
        for (int i = 0; i < n; i++) {
            vector<int> dp1(max_grundy + 1, 0);
            for (int j = 0; j <= max_grundy; j++) {
                // cerr << max_grundy << ", " << grundy[i] << ", " << (j ^ grundy[i]) << endl;
                dp1[j] = (dp[j] + dp[j ^ grundy[i]]) % MOD;
            }
            swap(dp, dp1);
        }

        int parity = 0;
        for (int i = 0; i < n; i++) {
            parity += grundy[i] == 1;
        }
        int ans = dp[0];
        if (parity == 0) {
            ans = (ans - 1 + MOD) % MOD;
        }
        cout << ans << endl;
    }
}
