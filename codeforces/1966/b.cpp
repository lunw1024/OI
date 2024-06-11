#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<vector<int>>> a(2, vector<vector<int>>(2, vector<int>(2)));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[i][j][0] = int(1e9);
                a[i][j][1] = -int(1e9);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                a[c == 'W'][0][0] = min(a[c=='W'][0][0], i);
                a[c == 'W'][0][1] = max(a[c=='W'][0][1], i);
                a[c == 'W'][1][0] = min(a[c=='W'][1][0], j);
                a[c == 'W'][1][1] = max(a[c=='W'][1][1], j);
            }
        }
        bool ans = false;
        for (int i = 0; i < 2; i++) {
            if (a[i][0][0] == 0 && a[i][0][1] == n - 1 && a[i][1][0] == 0 && a[i][1][1] == m - 1) {
                ans = true;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}
