// SoS dp over the set R of required characters for a substring

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int MOD = 998244353;
int N, Q;
string s;
vector<vector<ll>> dp(18, vector<ll>(1 << 17)); // substrings: R -> d + f

void preprocess(int q) {
    vector<ll> pow(N + 1);
    pow[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow[i] = pow[i - 1] * q % MOD;
    }

    // preprocess substrings
    int n = 0;
    for (char c : s) {
        n += c == '?';
    }
    // odd
    for (int i = 0; i < N; i++) {
        int f = 0, d = n, mask = 0;
        if (s[i] == '?') {
            f += 1;
            d -= 1;
        }
        dp[q][mask] += pow[f + d];
        for (int l = 1; i - l >= 0 && i + l < N; l++) {
            char a = s[i - l], b = s[i + l];
            if (a == '?' && b == '?') {
                f += 1, d -= 2;
            } else if (a == '?' || b == '?') {
                char c = a == '?' ? b : a;
                mask |= 1 << (c - 'a');
                d -= 1;
            } else if (a != b) {
                break;
            }
            dp[q][mask] += pow[f + d];
        }
    }
    // even
    for (int i = 0; i < N - 1; i++) {
        int f = 0, d = n, mask = 0;
        for (int l = 1; i + 1 - l >= 0 && i + l < N; l++) {
            char a = s[i + 1 - l], b = s[i + l];
            if (a == '?' && b == '?') {
                f += 1, d -= 2;
            } else if (a == '?' || b == '?') {
                char c = a == '?' ? b : a;
                mask |= 1 << (c - 'a');
                d -= 1;
            } else if (a != b) {
                break;
            }
            dp[q][mask] += pow[f + d];
        }
    }
}

int main() {
    cin >> N;
    cin >> s;

    for (int q = 1; q <= 17; q++) {
        preprocess(q);
        // SoS DP
        for (int i = 0; i < 17; i++) {
            for (int mask = 0; mask < (1 << 17); mask++) {
                if (mask & (1 << i)) {
                    dp[q][mask] += dp[q][mask ^ (1 << i)];
                    dp[q][mask] %= MOD;
                }
            }
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string q;
        cin >> q;
        int mask = 0;
        for (char c : q) {
            mask |= 1 << (c - 'a');
        }
        cout << dp[q.size()][mask] << endl;
    }
}
