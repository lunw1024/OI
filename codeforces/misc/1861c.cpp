#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = static_cast<int>(1e9);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int l = 0, r = INF, len = 0;
        bool ans = true;
        for (char c : s) {
            if (c == '+') {
                len++;
            } else if (c == '-') {
                len--;
                if (r > len) {
                    r = INF;
                }
                if (l > len) {
                    l = len;
                }
            } else if (c == '1') {
                l = max(l, len);
            } else {
                r = min(r, len);
            }
            if (l >= r || r < 2) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}

