#include <iostream>
#include <numeric>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using pii = pair<int, int>;
using vi = vector<int>;

struct Sieve {
    int n;
    vector<int> isprime, prime, least_pf;
    Sieve(int n) {
        this->n = n;
        isprime.resize(n, true);
        least_pf.resize(n);
        iota(least_pf.begin(), least_pf.end(), 0);
        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                prime.push_back(i);
            }
            for (int j : prime) {
                if (1ll * i * j >= n)
                    break;
                isprime[i * j] = false;
                least_pf[i * j] = j;
                if (i % j == 0)
                    break;
            }
        }
    }
};


void solve() {
    int n;
    cin >> n;
    Sieve sieve(n + 1);
    vi ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (!sieve.isprime[i]) {
            swap(ans[i], ans[i / sieve.least_pf[i]]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

