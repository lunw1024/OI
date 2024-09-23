#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        int ans = n;
        for (int i = 0; i <= 30; i++) {
            int offset = n % (1 << i);
            int d = (1<<i) - offset;
            if (n > (1 << i)) {
                d = min(d, offset + 1);
            }
            if (m >= d) {
                ans |= 1 << i;
            }
        }
        cout << ans << endl;
    }
}
