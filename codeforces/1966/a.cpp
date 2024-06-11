#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(101);
        int ans = n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            if (cnt[x] == k) {
                ans = k - 1;
            }
        }
        cout << ans << endl;
    }
}
