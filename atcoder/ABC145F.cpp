#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, K;
ll dp[301][301] = {0};
vector<int> h;

int main() {
    cin >> N >> K;
    h.push_back(0);
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        h.push_back(a);
    }
    h.push_back(0);
    fill(&dp[0][0], &dp[N + 1][K + 1], (ll)1e18);
    dp[0][0] = 0;
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k <= min(i - 1, j); k++) {
                dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + max(h[i - k - 1] - h[i], 0));
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + max(0, h[i - 1] - h[i]));
        }
    }
    cout << dp[N + 1][K] << endl;
}