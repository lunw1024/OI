#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vi a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vi> ans(n + 5, vi(2));
        for (int i = 0; i < n + 1; i += 2) {
            ans[i][0] = a[i / 2];
            ans[i][1] = a[m - 1 - i / 2];
            ans[i + 1][0] = a[m - 1 - i / 2];
            ans[i + 1][1] = a[i / 2];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                cout << ans[i][j % 2] << " ";
            }
            cout << endl;
        }
    }
}

