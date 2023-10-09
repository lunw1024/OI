#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, P;
ll dp[6][6][6][6][6];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K >> P;
    for (int i1 = P; i1 >= 0; i1--) {
        for (int i2 = P; i2 >= 0; i2--) {
            for (int i3 = P; i3 >= 0; i3--) {
                for (int i4 = P; i4 >= 0; i4--) {
                    for (int i5 = P; i5 >= 0; i5--) {
                        dp[i1][i2][i3][i4][i5] = ll(1e18);
                    }
                }
            }
        }
    }
    dp[0][0][0][0][0] = 0;
    for (int q = 0; q < N; q++) {
        ll c;
        cin >> c;
        vector<int> k(5);
        for (int i = 0; i < K; i++) {
            cin >> k[i];
        }
        for (int i1 = P; i1 >= 0; i1--) {
            for (int i2 = P; i2 >= 0; i2--) {
                for (int i3 = P; i3 >= 0; i3--) {
                    for (int i4 = P; i4 >= 0; i4--) {
                        for (int i5 = P; i5 >= 0; i5--) {
                            // if (dp[i1][i2][i3][i4][i5] + c < dp[min(i1 + k[0], P)][min(i2 + k[1], P)][min(i3 + k[2], P)][min(i4 + k[3], P)][min(i5 + k[4], P)]) {
                            //     cerr << "updating from " << dp[i1][i2][i3][i4][i5] << " at " << i1 << i2 << i3 << i4 << i5 << endl;
                            // }
                            dp[min(i1 + k[0], P)][min(i2 + k[1], P)][min(i3 + k[2], P)][min(i4 + k[3], P)][min(i5 + k[4], P)] = min(dp[i1][i2][i3][i4][i5] + c, dp[min(i1 + k[0], P)][min(i2 + k[1], P)][min(i3 + k[2], P)][min(i4 + k[3], P)][min(i5 + k[4], P)]);
                        }
                    }
                }
            }
        }
    }
    // for (int i1 = P; i1 >= 0; i1--) {
    //     for (int i2 = P; i2 >= 0; i2--) {
    //         for (int i3 = P; i3 >= 0; i3--) {
    //             for (int i4 = P; i4 >= 0; i4--) {
    //                 for (int i5 = P; i5 >= 0; i5--) {

    //                     cout <<  << endl;
    //                 }
    //             }
    //         }
    //     }
    // }
    ll ans = dp[P][P][P][P][P];
    if (K == 5) {
        ans = dp[P][P][P][P][P];
    } else if (K == 4) {
        ans = dp[P][P][P][P][0];
    } else if (K == 3) {
        ans = dp[P][P][P][0][0];
    } else if (K == 2) {
        ans = dp[P][P][0][0][0];
    } else if (K == 1) {
        ans = dp[P][0][0][0][0];
    }
    cout << (ans == ll(1e18) ? -1 : ans) << endl;
}
