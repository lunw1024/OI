#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int T;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        if (m == 1) {
            cout << 0 << endl;
            for (int i = 0; i < n; i++) {
                cout << 0 << endl;
            }
            continue;
        }

        vector<vector<int>> a(n, vector<int>(m));
        int ans = min(m, n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = ((-i + j - 1 + (i % m == m - 1)) % m + m) % m;
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
