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
        ll n;
        cin >> n;
        ll ans = 1;
        while (n > 3) {
            n /= 4;
            ans *= 2;
        }
        cout << ans << endl;
    }
}

