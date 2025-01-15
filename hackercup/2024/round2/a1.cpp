#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll a, b, m;
        cin >> a >> b >> m;
        // cerr << a << " " << b << " " << m << endl;
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= i; j++) {
                vector<char> v;
                for (int k = j; k <= i; k++) {
                    v.push_back(char('0' + k));
                }
                for (int k = i - 1; k >= j; k--) {
                    v.push_back(char('0' + k));
                }
                string s(v.begin(), v.end());
                ll x = stoll(s);
                // cerr << x << endl;
                if (x % m == 0 && a <= x && x <= b) {
                    ans++;
                    // cerr << "yes" << endl;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
