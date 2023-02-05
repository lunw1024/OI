#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> N >> k;
        int p = 0;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x == p + 1) {
                p++;
            }
        }
        cout << int(ceil(float(N - p) / k)) << endl;
    }
}
