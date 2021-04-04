#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int X, Y;
        cin >> X >> Y;
        string s;
        cin >> s;
        char prev = '?';
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?')
                continue;
            if (prev != '?' && s[i] != prev) {
                ans += prev == 'C' ? X : Y;
            }
            prev = s[i];
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
