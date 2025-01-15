#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m -= s.size();
            ans += m >= 0;
        }
        cout << ans << endl;
    }
}
