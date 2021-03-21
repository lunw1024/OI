// dp[i][j]: < i-th prefix, j distinct integers, not all 0s
// only 1 possibility is topped (the prefix)
// dp[i][j] = (16-j+1) * dp[i-1][j-1]       - unused
//            + j * dp[i-1][j]              - used
//            + (unused and < A[i]) * (C[i-1]==j)  - used and topped
//            + (used and < A[i]) * (C[i-1]==j-1) - unused and topped
// dp[i][1] += 15                           - preceding zeros
// maintain cnt, used[], and unused[]
#include <iostream>
#include <algorithm>
#include <vector>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using mint = modint1000000007;

vector<int> N;
int K;

int main() {
    string s;
    cin >> s;
    for (char ch : s) {
        if (ch <= '9')
            N.push_back(ch - '0');
        else
            N.push_back(10 + ch - 'A');
    }
    cin >> K;
    
    vector<vector<mint>> dp(N.size() + 1, vector<mint>(17));
    dp[1][1] = N[0] - 1;
    int unique = 1;
    vector<bool> used(16); // used/unused digits
    used[N[0]] = true;
    for (int i = 2; i <= N.size(); i++) {
        for (int j = 1; j <= 16; j++) {
            dp[i][j] = (16-j+1) * dp[i-1][j-1] + j * dp[i-1][j];
        }
        // topped
        int a = 0, b = 0;
        for (int j = 0; j < N[i-1]; j++) {
            a += used[j];
            b += !used[j];
        }
        dp[i][unique] += a;
        if (unique < 16)
            dp[i][unique + 1] += b;
        // all zeros
        dp[i][1] += 15;
        if (!used[N[i-1]]) {
            unique += 1;
            used[N[i-1]] = true;
        }
    }
    // for (int i = 1; i <= N.size(); i++) {
    //     for (int j = 0; j <= 16; j++)
    //         cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }
    cout << dp[N.size()][K].val() + (unique == K) << endl;
}