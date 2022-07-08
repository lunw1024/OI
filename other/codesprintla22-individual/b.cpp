#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans++;
            s[i] = '0';
            if (i < n - 2 && s[i + 1] == '1') {
                s[i + 1] = '0';
                s[i + 2] = '1';
            }
        }
    }
    cout << ans << endl;
}
