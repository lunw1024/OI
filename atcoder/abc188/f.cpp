#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
using ll = long long;

const ll INF = (ll)1e18;

int bc(ll x) {
    int out = 0;
    while (x > 0) {
        x >>= 1;
        out++;
    }
    return out;
}

ll dp[65][2];

int main() {
    ll X, Y;
    cin >> X >> Y;
    if (X >= Y) {
        cout << X - Y << endl;
        return 0;
    }

    for (int i = 0; i <= 64; i++) {
        dp[i][0] = INF;
        dp[i][1] = INF;
    }

    ll target = Y >> bc(Y) - bc(X);
    dp[bc(X)][0] = min(abs(X - target), 1 + abs(X * 2 - target));
    target++;
    dp[bc(X)][1] = min(abs(X - target), 1 + abs(X * 2 - target));

    target = Y >> max(0, bc(Y) - bc(X) - 1);
    dp[bc(X) + 1][0] = min(abs(X - target), min(1 + abs(X * 2 - target), 2 + abs(X * 4 - target)));
    target++;
    dp[bc(X) + 1][1] = min(abs(X - target), min(1 + abs(X * 2 - target), 2 + abs(X * 4 - target)));

    target = Y >> bc(Y) - bc(X) + 1;
    dp[bc(X) - 1][0] = abs(X - target);
    target++;
    dp[bc(X) - 1][1] = abs(X - target);

    for (int i = bc(X); i <= bc(Y); i++) {
        if ((Y >> bc(Y) - i) & 1ll) {
            dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + 2, dp[i - 1][1] + 2)); // 2S + 1
            dp[i][1] = min(dp[i][1], min(dp[i - 1][0] + 3, dp[i - 1][1] + 1)); // 2S + 2
        } else {
            dp[i][0] = min(dp[i][0], min(dp[i - 1][0] + 1, dp[i - 1][1] + 3)); // 2S
            dp[i][1] = min(dp[i][1], min(dp[i - 1][0] + 2, dp[i - 1][1] + 2)); // 2S + 1
        }
    }
    ll ans = min(dp[bc(Y)][0], dp[bc(Y)][1] + 1);
    cout << ans << endl;
}