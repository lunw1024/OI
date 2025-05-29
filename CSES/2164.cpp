#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int jq(int k, int n) {
    // cerr << k << ", " << n << endl;
    if (k == 1 && n == 1) {
        return 1;
    }
    if (k <= n / 2) {
        return k * 2;
    }
    if (n % 2 == 0) {
        return jq(k - n / 2, n - n / 2) * 2 - 1;
    } else {
        int x = jq(k - n / 2, n - n / 2);
        if (x == 1) {
            return n;
        } else {
            return (x - 1) * 2 - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int k, n;
        cin >> n >> k;
        cout << jq(k, n) << endl;
    }
}

