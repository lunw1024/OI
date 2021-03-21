#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string S, X;
vector<int> v;

int main() {
    cin >> N >> S >> X;
    v.resize(N);
    for (int i = N - 1, a = 1; i >= 0; i--, a = a * 10 % 7) {
        v[i] = a * (S[i] - '0') % 7;
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(7));
    dp[N][0] = true;
    for (int i = N - 1; i >= 0; i--) {
        if (X[i] == 'T') {
            for (int j = 0; j < 7; j++) {
                dp[i][j] = dp[i+1][j] || dp[i+1][(j-v[i]+7) % 7];
            }
        } else {
            for (int j = 0; j < 7; j++) {
                dp[i][j] = dp[i+1][j] && dp[i+1][(j-v[i]+7) % 7];
            }
        }
    }
    cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;
}
