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
        int n, k;
        cin >> n >> k;
        vi a(n);
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maximum = max(maximum, a[i]);
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int l = 1, r = maximum + k;
            while (l <= r) {
                int mid = (l + r) / 2;
                bool ok = true;
                int budget = k;
                for (int j = i; j < n; j++) {
                    int target = mid - (j - i);
                    if (a[j] >= target) {
                        break;
                    }
                    if (j == n - 1 && a[j] < target) {
                        ok = false;
                    }
                    budget -= target - a[j];
                    if (budget < 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, r);
        }
        cout << ans << endl;
    }
}

