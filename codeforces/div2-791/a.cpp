#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        ll n;
        cin >> n;
        if (n % 2 == 1 || n == 2) {
            cout << -1 << endl;
        } else {
            cout << (n / 6 + (n % 6 > 0)) << " " << (n / 4) << endl;
        }
    }
}

