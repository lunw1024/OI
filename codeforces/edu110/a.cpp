#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (min(a, b) > max(c, d) || max(a, b) < min(c, d)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
