#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll r, b, k;
        cin >> r >> b >> k;
        ll g = gcd(r, b);
        r /= g;
        b /= g;
        if (r > b) {
            swap(r, b);
        }
        ll maximum = ll(ceil(double(b - 1) / r));
        if (maximum >= k) {
            cout << "REBEL" << endl;
        } else {
            cout << "OBEY" << endl;
        }
    }
}

