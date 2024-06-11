#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = n - 1; i > 0; i--) {
            a[i] -= a[i - 1];
        }
        bool alice = false;
        for (int x : a) {
            if (x == 0) {
                continue;
            }
            if (x == 1) {
                alice = !alice;
            } else {
        for (int i = 0; i < n; i++) {
            
        }
                alice = !alice;
                break;
            }
        }
        cout << (alice ? "Alice" : "Bob") << endl;
    }
}
