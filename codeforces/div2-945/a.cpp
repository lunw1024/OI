#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) % 2 == 1) {
            cout << -1 << endl;
        } else {
            if (c > a + b) {
                cout << (a + b) << endl;
            } else {
                cout << (a + b + c) / 2 << endl;
            }
        }
    }
}
