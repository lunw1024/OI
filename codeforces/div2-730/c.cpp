#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

int N;
ld v;
ld eps = 1e-7;

ld dfs(ld c, ld m, int d) {
    ld ans = d * (1 - c - m);
    // cerr << "at " << c << " " << m << " " << p << " " << d << endl;
    // cerr << "base ans = " << d << " * " << p << " = " << ans << endl;
    if (c > eps) {
        if (c < v + eps) {
            if (m > eps) {
                ans += c * dfs(0, m + c / 2, d + 1);
            } else {
                ans += c * dfs(0, 0, d + 1);
            }
        } else {
            if (m > eps) {
                ans += c * dfs(c - v, m + v / 2, d + 1);
            } else {
                ans += c * dfs(c - v, 0, d + 1);
            }
        }
    }
    if (m > eps) {
        if (m < v + eps) {
            if (c > eps) {
                ans += m * dfs(c + m / 2, 0, d + 1);
            } else {
                ans += m * dfs(0, 0, d + 1);
            }
        } else {
            if (c > eps) {
                ans += m * dfs(c + v / 2, m - v, d + 1);
            } else {
                ans += m * dfs(0, m - v, d + 1);
            }
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ld c, m, p;
        cin >> c >> m >> p >> v;
        cout << fixed << setprecision(7) << dfs(c, m, 1) << endl;
    }
}