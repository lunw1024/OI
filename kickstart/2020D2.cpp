#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N;
        int a = 0, b = 0, c = 0, d = 0, prev;
        cin >> prev;
        for (int i = 2; i <= N; i++) {
            int x, na, nb, nc, nd;
            cin >> x;
            if (x < prev) {
                na = min(min(a + 1, b), min(c, d));
                nb = min(min(a + 1, b + 1), min(c, d));
                nc = min(min(a + 1, b + 1), min(c + 1, d));
                nd = min(min(a + 1, b + 1), min(c + 1, d + 1));
            } else if (x > prev) {
                nd = min(min(a, b), min(c, d + 1));
                nc = min(min(a, b), min(c + 1, d + 1));
                nb = min(min(a, b + 1), min(c + 1, d + 1));
                na = min(min(a + 1, b + 1), min(c + 1, d + 1));
            } else {
                na = min(min(a, b + 1), min(c + 1, d + 1));
                nb = min(min(a + 1, b), min(c + 1, d + 1));
                nc = min(min(a + 1, b + 1), min(c, d + 1));
                nd = min(min(a + 1, b + 1), min(c + 1, d));
            }
            a = na, b = nb, c = nc, d = nd;
            prev = x;
            // cout << a << " " << b << " " << c << " " << d << endl;
        }
        cout << "Case #" << caseNo << ": " << min(min(a, b), min(c, d)) << endl;;
    }
}