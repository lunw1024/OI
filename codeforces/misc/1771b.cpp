#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i].second >> a[i].first;
            if (a[i].second > a[i].first) {
                swap(a[i].first, a[i].second);
            }
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        int j = 0, p = 0;
        for (int i = 1; i <= n; i++) {
            while (p < a.size() && a[p].first <= i) {
                j = max(j, a[p].second);
                p++;
            }
            ans += (i - j);
        }
        cout << ans << endl;
    }
}
