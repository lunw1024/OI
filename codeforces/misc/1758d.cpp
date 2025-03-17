#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<ll> c(n);
        ll sc = ll(n + 1) * (n + 1) - n * ll(n + 1) / 2 - 2;
        // cerr << n << "sc = " << sc << endl;
        ll k = sc / n;
        sc %= n;
        c[0] = 0;
        c[n - 1] = 2;
        for (int i = n - 2; i >= 1; i--) {
            c[i] = min(2ll, sc);
            sc -= c[i];
        }
        assert(sc == 0);
        for (int i = 0; i < n; i++) {
            c[i] += k;
        }
        for (int i = 0; i < n; i++) {
            c[i] += i + 1;
            cout << c[i] << " ";
        }
        cout << endl;
        
    }
}

