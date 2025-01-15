#include <iostream>
#include <ostream>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        ll s = 0, g = 0;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (i % 2 == 0) {
                s += x;
            } else {
                g += x;
            }
        }
        if (s % ((n + 1) / 2) == 0 && g % (n / 2) == 0) {
            if (s / ((n+1)/2) == g / (n/2)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}
