#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int gap = 1;
        vector<int> last(20, -1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < 20; j++) {
                int b = x % 2;
                if (b) {
                    gap = max(gap, i - last[j]);
                    last[j] = i;
                }
                x >>= 1;
            }
        }
        for (int j = 0; j < 20; j++) {
            if (last[j] >= 0) {
            gap = max(gap, n - last[j]);
            }
        }
        cout << gap << endl;
    }
}
