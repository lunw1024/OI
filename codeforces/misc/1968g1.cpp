#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

vector<int> z_function(string s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k >> k;
        string s;
        cin >> s;
        auto z = z_function(s);
        z[0] = n;
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0, p = 0;
            while (p < n) {
                if (z[p] >= mid) {
                    p += mid;
                    cnt++;
                } else {
                    p++;
                }
            }
            if (cnt >= k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        int ans = r;
        cout << ans << endl;
    }
}

