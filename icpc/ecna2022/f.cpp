#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numbers>
using namespace std;
using namespace std::numbers;
using ll = long long;
using ld = long double;

int main() {
    ll r, s, h;
    cin >> r >> s >> h;
    ld T = std::numbers::pi_v<ld> * 2 * r;
    ld T_dec = T - static_cast<ll>(floorl(T)) / (s * h) * (s * h);
    if (T_dec * 2 >= s * h) {
        T_dec = s * h - T_dec;
    }
    // cerr << static_cast<ll>(floorl(T)) % (s * h) << endl;
    // cerr << T << " " << T_dec << endl;
    ld best = 1e18;
    int a = 0, b = 0, c = 0;
    for (int i = 2; i <= 1000; i++) {
        for (int j = i * 2; j <= 1000; j += i) {
            for (int k = j * 2; k <= 1000; k += j) {
                int n = k / i - k / j + 1;
                ld diff = abs(n * s * h / static_cast<ld>(k) - T_dec);
                if (diff < best) {
                    best = diff;
                    a = i;
                    b = j;
                    c = k;
                }
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
}
