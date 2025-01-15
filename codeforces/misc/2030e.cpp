// how do you even calc score?
// dp over the size of the rightmost group: extend vs new group
// This is O(n^2) naively?
// extend: basically keep everything unchanged
// new group: dp[i] <- max(dp[j] + mex(j..i-1) for j = 0..i-1)
// thus this can be simplified to: calc ans for every prefix.
// every inductive step is a max(dp[j] + mex[j+1..i]).
// still O(n^2)
// is calculating the sum of scores easier?
// misread the problem. the partitions don't have to be contiguous.
// thus do an dp over # of sets with mex k
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MOD = 998244353;

int pow(int a, int x) {
    a = a % MOD;
    int out = 1;
    while (x > 0) {
        if (x & 1) {
            out = (ll(out) * a) % MOD;
        }
        a = (ll(a) * a) % MOD;
        x >>= 1;
    }
    return out;
}

int inv(int x) {
    return pow(x, MOD - 2);
}

struct Choose {
    int _n;
    vector<int> fact;
    
    Choose(int n) {
        _n = n;
        fact.resize(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = ll(fact[i - 1]) * i % MOD;
        }
    }

    int c(int n, int r) {
        return fact[n] * inv(fact[r]) * inv(fact[n - r]);
    }
};

int main() {
    int T;
    cin >> T;
    Choose choose(int(2e5) + 1);
    vector<int> pow2(int(2e5) + 1);
    pow2[0] = 1;
    for (int i = 1; i < int(1e5) + 1; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    for (int t = 0; t < T; t++) {
        // cerr << "Case " << t << endl;
        int n;
        cin >> n;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        vector<int> dp(n + 1); // dp[k] = num of ways to make min(cnt[1..i] = k)
        // init: dp[n] = 1
        dp[n] = 1;
        ll ans = 0;
        int suf_len = n;
        for (int i = 0; i < n; i++) {
            // make suffix sum of dp, called suf
            // for i being the smallest: dp[j] += (cnt[i] choose j) * suf[j]
            // for i not being the smallest: dp[j] += sum(cnt[i] choose k, for k = j+1..cnt[i]) * dp_old[j]
            suf_len -= cnt[i];
            if (cnt[i] == 0) {
                break;
            }
            vector<int> dp_new(min(cnt[i] + 1, int(dp.size())));
            vector<int> suf(dp.size());
            suf[dp.size() - 1] = dp[dp.size() - 1];
            // cerr << "stage 1" << endl;
            for (int j = int(dp.size()) - 2; j >= 0; j--) {
                suf[j] = (suf[j + 1] + dp[j]) % MOD;
            }
            int sum_bino = 0;
            for (int j = cnt[i]; j >= dp_new.size(); j--) {
                sum_bino = (sum_bino + choose.c(cnt[i], j)) % MOD;
            }
            // cerr << "stage 2" << endl;
            for (int j = int(dp_new.size()) - 1; j >= 0; j--) {
                dp_new[j] += ll(choose.c(cnt[i], j)) * suf[j] % MOD;
                dp_new[j] %= MOD;
                dp_new[j] += ll(sum_bino) * dp[j] % MOD;
                dp_new[j] %= MOD;
                sum_bino = (sum_bino + choose.c(cnt[i], j)) % MOD;
                ans += ll(dp_new[j]) * j % MOD * pow2[suf_len] % MOD;
                ans %= MOD;
            }
            // for (int j = 0; j < dp_new.size(); j++) {
            //     cerr << dp_new[j] << " ";
            // }
            // cerr << endl;
            swap(dp_new, dp);
        }
        cout << ans << endl;
        // cerr << "2C2 = " << choose.c(2, 2) << endl;
    }
}

