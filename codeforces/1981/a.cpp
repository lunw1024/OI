#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int l, r;
        cin >> l >> r;
        cout << int(log2(r)) << endl;
    }
}
