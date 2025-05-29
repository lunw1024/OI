// n + 2 (n - best intersection size)
// impossible if any element is not achievable
// O(nm * 10)
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
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int best = 0;
        vector<bool> vis(n);
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                string b;
                cin >> b;
                if (b == a[j]) {
                    vis[j] = true;
                    cnt++;
                }
            }
            best = max(best, cnt);
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= vis[i];
        }
        int ans = 3 * n - 2 * best;
        cout << (ok ? ans : -1) << endl;
    }
}

