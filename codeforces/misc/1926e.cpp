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
        int k, n;
        cin >> n >> k;
        int cnt = n;
        for (int i = 0; i < 100; i++) {
            int m = (cnt + 1) / 2;
            if (k <= m) {
                cout << ((1 << i) + (k - 1) * (2 << i)) << endl;
                break;
            }
            k -= m;
            cnt -= m;
        }
    }
}

