#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vi cnt(101);
        for (int x : a) {
            cnt[x % k]++;
        }
        bool win = false;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            if (cnt[x % k] == 1) {
                win = true;
                ans = i + 1;
            }
        }
        if (win) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

