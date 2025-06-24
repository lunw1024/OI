#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    const int bit = (1 << 30), bit1 = (1 << 29);
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vi ans(n);
        int x = 0, y = 0;
        for (int i = 2; i < n; i += 2) {
            ans[i] = i == 2 ? bit1 : i;
            x ^= ans[i];
        }
        for (int i = 3; i < n; i += 2) {
            ans[i] = i;
            y ^= ans[i];
        }
        assert(x != y);
        ans[0] = bit ^ x;
        ans[1] = bit ^ y;
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}

