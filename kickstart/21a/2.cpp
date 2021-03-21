#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C;
        cin >> R >> C;
        vector<vector<bool>> A(R, vector<bool>(C));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int temp;
                cin >> temp;
                A[i][j] = temp == 1;
            }
        }
        vector<vector<int>> l(R, vector<int>(C)), r(R, vector<int>(C)), u(R, vector<int>(C)), d(R, vector<int>(C));
        for (int i = 0; i < R; i++) {
            int len = 0;
            for (int j = 0; j < C; j++) {
                len = A[i][j] ? len + 1 : 0;
                l[i][j] = len;
            }
        }

        for (int i = 0; i < R; i++) {
            int len = 0;
            for (int j = C - 1; j >= 0; j--) {
                len = A[i][j] ? len + 1 : 0;
                r[i][j] = len;
            }
        }

        for (int i = 0; i < C; i++) {
            int len = 0;
            for (int j = 0; j < R; j++) {
                len = A[j][i] ? len + 1 : 0;
                u[j][i] = len;
            }
        }

        for (int i = 0; i < C; i++) {
            int len = 0;
            for (int j = R - 1; j >= 0; j--) {
                len = A[j][i] ? len + 1 : 0;
                d[j][i] = len;
            }
        }

        int ans = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // cout << i << " " << j << " " << u[i][j] << " " << r[i][j] << endl;
                ans += max(0, min(u[i][j], r[i][j] / 2) - 1) + max(0, min(u[i][j] / 2, r[i][j]) - 1);
                ans += max(0, min(r[i][j], d[i][j] / 2) - 1) + max(0, min(r[i][j] / 2, d[i][j]) - 1);
                ans += max(0, min(d[i][j], l[i][j] / 2) - 1) + max(0, min(d[i][j] / 2, l[i][j]) - 1);
                ans += max(0, min(l[i][j], u[i][j] / 2) - 1) + max(0, min(l[i][j] / 2, u[i][j]) - 1);
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}