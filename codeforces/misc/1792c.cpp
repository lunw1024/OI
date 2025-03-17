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
        vi a(n + 1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[x] = i;
        }
        int ans = n / 2;
        for (int i = n / 2; i >= 1; i--) {
            if (a[i] < a[i + 1] && a[n - i] < a[n + 1 - i]) {
                ans--;
            } else {
                break;
            }
        }
        cout << ans << endl;
    }
}

