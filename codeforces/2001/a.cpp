#include <iostream>
#include <vector>
using namespace std;


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1);
        int ans = n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            ans = min(ans, n - cnt[x]);
        }
        cout << ans << endl;
    }
}
