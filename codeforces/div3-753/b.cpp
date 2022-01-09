#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll x, n;
        cin >> x >> n;
        ll res = n % 4;
        ll sign = 2 * ((x % 2 + 2) % 2) - 1;
        if (res == 1) {
            x += sign * n;
        } else if (res == 2) {
            x -= sign;
        } else if (res == 3) {
            x -= sign * (n + 1);
        }
        cout << x << "\n";
    }
    cout << endl;
}