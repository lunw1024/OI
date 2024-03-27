#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        for (int d = 1; d <= n / 2; d++) {
            int cnt = 0;
            for (int i = 0; i < n - d; i++) {
                if (s[i] == '?' || s[i + d] == '?' || s[i] == s[i + d]) {
                    cnt++;
                } else {
                    cnt = 0;
                }
                if (cnt == d) {
                    ans = d;
                    break;
                }
            }
        }
        cout << ans * 2 << endl;
    }
}
