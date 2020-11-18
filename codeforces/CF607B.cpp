#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[502], dp[502][502];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
    }
    for (int l = 2; l <= N; l++) {
        for (int i = 1; i + l - 1 <= N; i++) {
            int j = i + l - 1;
            dp[i][j] = dp[i + 1][j] + 1;
            for (int k = i + 1; k <= j; k++) {
                if (arr[i] == arr[k])
                    dp[i][j] = min(dp[i][j], max(1, dp[i + 1][k - 1]) + dp[k + 1][j]);
            }
        }
    }
    cout << dp[1][N] << endl;
}