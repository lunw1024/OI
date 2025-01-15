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
        int n;
        cin >> n;
        vi a(n);
        int ans = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 0) {
                ans = 1 + flag;
            }
            if (ans == 1 && a[i] == 0) {
                flag = true;
            }
        }
        cout << ans << endl;
    }
}

