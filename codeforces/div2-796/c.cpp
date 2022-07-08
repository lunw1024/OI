#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        vector<int> cnt(26);
        for (int i = 0; i < 2 * n; i++) {
            string s;
            cin >> s;
            for (char c : s) {
                cnt[c - 'a']++;
            }
        }
        string s;
        cin >> s;
        for (char c : s) {
            cnt[c - 'a']++;
        }
        char ans;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                ans = 'a' + i;
            }
        }
        cout << ans << endl;
    }
}
