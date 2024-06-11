#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 3;
        for (int i = 0; i < n; i++) {
            if (a[a[i] - 1] == i + 1) {
                ans = 2;
            }
        }
        cout << ans << endl;
    }
}
