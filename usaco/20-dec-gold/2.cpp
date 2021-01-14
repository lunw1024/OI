#include <atcoder/all>
#include <iostream>
#include <map>
using namespace atcoder;
using namespace std;

using mint = modint1000000007;

int N;
string S;
mint dp[(int)1e5 + 1][4][4][4] = {0};
const char AGCT[4] = {'A', 'G', 'C', 'T'};
map<char, int> ID = {{'A', 0}, {'G', 1}, {'C', 2}, {'T', 3}};

int main() {
    cin >> S;
    N = S.size();
    for (int s = 0; s < 4; s++) {
        for (int n = 0; n < 4; n++) {
            for (int t = 0; t < 4; t++) {
                
            }
        }
    }

    for (int i = 0; i < S.size(); i++) {
        for (int s = 0; s < 4; s++) {
            for (int n = 0; n < 4; n++) {
                for (int t = 0; t < 4; t++) {
                    mint num = dp[i][s][n][t];
                    if (S[i + 1] == '?') {
                        for (int tp = 0; tp < 4; tp++) {
                            dp[i + 1][s][n][tp] += num;
                            if (s == t)
                                dp[i + 1][n][tp][tp] += num;
                        }
                    } else {
                        int tp = ID[S[i + 1]];
                        dp[i + 1][s][n][tp] += num;
                        if (s == t)
                            dp[i + 1][n][tp][tp] += num;
                    }
                }
            }
        }
    }
}

