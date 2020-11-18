#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9 + 7;
int N, HI;
int cnt[1 << 18 + 1], phi[1 << 18 + 1];
vector<int> prime;
ll dp[1 << 18];

void preprocess() {
    int MAXN = 1 << HI;
    phi[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (phi[i] == 0) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int p : prime) {
            if (p * i > MAXN)
                break;
            if (i % p != 0) {
                phi[i * p] = phi[i] * (p - 1);
            } else {
                phi[i * p] = phi[i] * p;
                break;
            }
        }
    }
}

int main() {
    cin >> N;
    int maximum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        maximum = max(maximum, a);
    }
    for (; maximum > 0; maximum >>= 1, HI++);

    preprocess();

    dp[0] = 1;
    for (int u = 1; u < (1 << HI); u++) {
        for (int s = u; ; s = (s - 1) & u) {
            int c = s ^ u;
            if (s < c) // no equal
                break;
            dp[u] = (dp[u] + dp[c] * cnt[s]) % MOD;
        }
    }

    ll ans = 1; // empty
    for (int u = 1; u < (1 << HI); u++) {
        ans = (ans + dp[u] * phi[u + 1]) % MOD;
    }
    for (int i = 0; i < cnt[0]; i++) {
        ans = ans * 2 % MOD;
    }

    cout << ans << endl;
}
