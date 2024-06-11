#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0) {
                ans = max(ans, min(a[i - 1], a[i]));
            }
            if (i > 1) {
                ans = max(ans, min(a[i - 2], a[i]));
            }
        }
        cout << ans << endl;
    }
}
