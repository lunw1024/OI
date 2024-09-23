#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = n - 1; i >= 2; i -= 2) {
            cout << i << " ";
        }
        cout << endl;
    }
}
