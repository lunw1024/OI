#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        N = s.size();
        ll o = 0, e = 0, x = 0, ans = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '0') {
                e++;
                e += x;
                x = 0;
                o = 0;
            } else if (s[i] == '1') {
                o++;
                o += x;
                x = 0;
                e = 0;
            } else {
                x++;
            }
            ans += o + e + x;
            swap(o, e);
        }
        cout << ans << endl;
    }
}
