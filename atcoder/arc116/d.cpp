#include <iostream>
#include <algorithm>
#include <vector>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using mint = modint998244353;

int N, M;

int main() {
    cin >> N >> M;
    vector<mint> C(N + 1); // C(N, i)
    C[0] = 1;
    for (int i = 1; i <= N; i++) {
        C[i] = C[i - 1] * (N - i + 1) / i;
    }

    vector<mint> dp(M + 1);
    dp[0] = 1;
    for (int i = 2; i <= M; i += 2) {
        for (int j = 0; j <= N and i - j >= 0; j += 2)
            dp[i] += C[j] * dp[(i - j) / 2];
    }
    cout << dp[M].val() << endl;
}