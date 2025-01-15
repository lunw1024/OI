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
        int n, x, y;
        cin >> n >> x >> y;
        vi ans(n + 1);
        ans[x] = 0;
        ans[y] = 1;
        for (int i = x + 1; i < y; i++) {
            ans[i] = 1 - ans[i - 1];
        }
        if (ans[y - 1] == 1) {
            ans[y - 1] = 2;
        }
        for (int i = x - 1; i >= 1; i--) {
            ans[i] = 1 - ans[i + 1];
        }
        for (int i = n; i > y; i--) {
            ans[i] = 1 - ans[i % n + 1];
        }
        if (ans[y % n + 1] == 1) {
            ans[y % n + 1] = 2;
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

