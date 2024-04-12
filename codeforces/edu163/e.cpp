#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> c(n);
        int m = ceil(n / k);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k / 2; j++) {
                a[i * k + j] = k / 2 - j + i * k;
            }
            for (int j = 0; j < k - k / 2; j++) {
                a[i * k + k / 2 + j] = k - j + i * k;
            }
            for (int j = 0; j < k; j++) {
                c[i * k + j] = i + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
    }
}
