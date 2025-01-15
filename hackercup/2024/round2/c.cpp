#include <iostream>
#include <algorithm>
#include <hash_map>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C;
        ll K;
        cin >> R >> C >> K;
        vector<vector<int>> color(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> color[i][j];
            }
        }
        vector<int> count(R * C + 1, 0), ans(801, 0);
        int tot = 0;
        for (int k = 1; k <= min(R, C); k++) {
            // make initial count
            int l = 0, r = 1;
            for (int i = 0; i < R - k; i++) {
                for (int j = 0; j < C; j++) {
                    cerr << "hi";
                    while (r < C && r < j + k) {
                        count[color[i + k][r]]++;
                        tot++;
                        r++;
                    }
                    while (l < j - k) {
                        count[color[i + k][l]]--;
                        tot--;
                        l++;
                    }
                    cerr << "ni";
                    ans[k] += tot - count[color[i][j]];
                }
            }

            l = 0, r = 1;
            tot = 0;
            fill(count.begin(), count.end(), 0);
            for (int i = 0; i < C - k - 1; i++) {
                for (int j = 0; j < R; j++) {
                    while (r < C && r < j + k) {
                        count[color[r][i + k - 1]]++;
                        tot++;
                        r++;
                    }
                    while (l < j - k) {
                        count[color[l][i + k - 1]]--;
                        tot--;
                        l++;
                    }
                    ans[k] += tot - count[color[j][i]];
                }
            }
        }
        K /= 2;
        for (int i = 1; i <= 800; i++) {
            // cerr << K << endl;
            if (K > ans[i]) {
                K -= ans[i];
            } else {
                cout << "Case #" << t << ": " << i << endl;
                break;
            }
        }
    }
}
