#include <atcoder/all>
#include <iostream>
#include <map>
using namespace atcoder;
using namespace std;

using ll = long long;

ll sign(ll x) {
    return x / abs(x);
}

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> bases(N);
    for (int i = 0; i < N; i++) {
        cin >> bases[i];
    }
    vector<ll> m(N);
    for (int i = 0; i < N - 1; i++) {
        m[i] = bases[i + 1] / bases[i] - 1;
    }
    m[N - 1] = (ll)1e15 + 1;
    // translate X
    vector<ll> a(N);
    ll temp = X;
    for (int i = N - 1; i >= 0; i--) {
        a[i] = temp / bases[i];
        temp %= bases[i];
    }

    // dp
    vector<map<ll, ll>> dp(N + 1, map<ll, ll>());
    dp[N][X] = 1;
    for (int i = N - 1; i >= 0; i--) {
        for (pair<ll, ll> e : dp[i + 1]) {
            ll d = e.first, v = e.second;
            // cout << "i = " << i + 1 << ", d = " << d << ", v = " << v << endl;
            dp[i][d % bases[i]] += v; // keep sign
            if (d % bases[i] != 0 && abs(d / bases[i]) < m[i]) { // flip sign
                dp[i][d % bases[i] - sign(d) * bases[i]] += v;
            }
        }
    }
    cout << dp[0][0] << endl;
}