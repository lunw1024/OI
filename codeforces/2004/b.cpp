#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) {
            swap(a, c);
            swap(b, d);
        }
        // cout << a << b << c << d << endl;
        int ans = (a < c) + min(b, d) - c + (b != d);
        ans = max(ans, 1);
        cout << ans << endl;
    }
}
