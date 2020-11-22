#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 501;
int N, K, A[MAXN], B[MAXN];
bool dp[MAXN][MAXN];
ll sum, ans;

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        sum += A[i] + B[i];
    }
    
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k <= min(K - 1, A[i]); k++) {
                dp[i][j] |= dp[i - 1][(K + j - k) % K] && (A[i] - k) % K + B[i] >= K;
            }
            dp[i][j] |= dp[i - 1][(K + j - A[i] % K) % K];
        }
    }

    for (int i = 0; i < K; i++) {
        if (dp[N][i])
            ans = max(ans, (sum - i) / K);
    }
    cout << ans << endl;
}
