#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int ans = 0;
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans += i > cnt ? i - cnt + 1 : 0;
                cnt++;
            }
        }
        cout << ans << endl;
    }
}
