#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int j = 0; j < n / 2; j++) {
            cout << (j % 2 == 0 ? "AA" : "BB");
        }
        cout << endl;
    }
}
