#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const ll M = 3600 * 12 * ll(1e9);
ll A, B, C, h, m, s, n;

bool solve(ll a, ll b, ll c) {
    // cerr << "a = " << a << "b = " << b << "c = " << c << endl;
    for (h = 0; h < 12; h++) {
        if ((ll(1e9) * 3600 * h - a + b) % 11 == 0) {
            n = (ll(1e9) * 3600 * h - a + b) / 11;
            // cerr << "h = " << h << endl;
            if (n < 0)
                continue;
            s = n / ll(1e9);
            n %= ll(1e9);
            m = s / 60;
            s %= 60;
            ll k = 12 * n + 12 * ll(1e9) * s + 12 * 60 * ll(1e9) * m - b; // diff
            ll aa = ((a + k) % M + M) % M;
            ll bb = ((b + k) % M + M) % M;
            ll cc = ((c + k) % M + M) % M;

            /* cerr << h << " " << m << " " << s << " " << n << endl;
            cerr << aa << " " << bb << " " << cc << endl;
            cerr << ll(1e9) * 720 * s + 720 * n << endl; */
            if (ll(1e9) * 720 * s + 720 * n == cc) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> A >> B >> C;
        if (solve(A, B, C)) {}
        else if (solve(A, C, B)) {}
        else if (solve(B, A, C)) {}
        else if (solve(B, C, A)) {}
        else if (solve(C, A, B)) {}
        else if (solve(C, B, A)) {}
        else {
            cout << "NOOO" << endl;
        }
        cout << "Case #" << t << ": " << h << " " << m << " " << s << " " << n << endl;
    }
}
