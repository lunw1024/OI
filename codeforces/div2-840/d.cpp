#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
const int MOD = int(1e9) + 7;
vector<vector<ll>> C;

void preprocess() {
    C.resize(101, vector<ll>(101));
    for (int i = 0; i <= 100; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    preprocess();
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, p, q, x, y;
        cin >> n >> p >> q >> x >> y;
        if (x < y) {
            // cout << "swap" << endl;
            swap(x, y);
            p = n + 1 - p;
            q = n + 1 - q;
            swap(p, q);
            // cout << p << " " << q << " " << x << " " << y << " " << endl;
        }
        ll ans = 0;

        if (x == n) {
            // special case
            if (p == 1) {
                cout << 0 << endl;
                continue;
            }
            ll res = 1;
            res *= C[n - y - 1][q - p - 1];
            res %= MOD;
            res *= C[y - 1][n - q];
            res %= MOD;
            cout << res << endl;
            continue;
        }


        // n x y
        ll case1 = 0;
        for (int i = 2; i < p; i++) {
            ll res = 1;
            res *= C[n - x - 1][p - i - 1];
            res %= MOD;
            res *= C[x - y - 1][q - p - 1];
            res %= MOD;
            res *= C[y - 1][n - q];
            res %= MOD;
            case1 += res;
        }

        // x n y
        ll case2 = 0;
        for (int i = p + 1; i < q; i++) {
            ll res = 1;
            res *= C[n - x - 1][i - p - 1];
            res %= MOD;
            // cout << "C(" << n - x - 1 << ", " << i - p - 1 << ")" << endl;
            int z = n - x - 1 - (i - p - 1);
            if (z < 0) {
                // cerr << "failed on i = " << i << endl;
                assert(res == 0);
                continue;
            }
            if (q - i - 1 - z < 0) {
                continue;
            }
            res *= C[x - y - 1][q - i - 1 - z];
            // cout << "C(" << x - y - 1 << ", " << q - i - 1 - z << ")" << endl;
            res %= MOD;
            z = x - y - 1 - (q - i - 1 - z);
            if (z < 0) {
                // cerr << "failed on i = " << i << endl;
                assert(res == 0);
                continue;
            }
            if (p - 1 - z < 0) {
                continue;
            }
            res *= C[y - 1][p - 1 - z];
            // cout << "C(" << y - 1 << ", " << p - 1 - z << ")" << endl;
            res %= MOD;
            case2 += res;
        }
        ans = (case1 + case2) % MOD;
        // cout << "case1 = " << case1 << ", case2 = " << case2 << endl;
        cout << ans << endl;
    }
}
