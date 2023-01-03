#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        if ((a == c || a == e || c == e) && (b == d || b == f || d == f)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
