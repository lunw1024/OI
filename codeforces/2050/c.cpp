#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int n = s.size();
        vector<bool> dp(9);
        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        dp[sum % 9] = true;
        for (char c : s) {
            vector<bool> ndp(dp);
            if (c == '2') {
                for (int i = 0; i < 9; i++) {
                    ndp[(i + 2) % 9] = ndp[(i + 2) % 9] || dp[i];
                }
            }
            if (c == '3') {
                for (int i = 0; i < 9; i++) {
                    ndp[(i + 6) % 9] = ndp[(i + 6) % 9] || dp[i];
                }
            }
            dp = ndp;
        }
        cout << (dp[0] ? "YES" : "NO") << endl;
    }
}
