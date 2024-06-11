#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int val = 0;
        int prev = -int(1e9);
        int ans = int(1e9);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i == 0) {
                val = x;
            }            
            if (x != val) {
                ans = min(ans, i);
                ans = min(ans, i - prev - 1);
                prev = i;
            }
        }
        ans = min(ans, n - prev - 1);
        cout << (ans == int(1e9) ? -1 : ans) << endl;
    }
}
