#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int m = n / 2;
        vector<int> a(n);
        int offset = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == n) {
                offset = i % 2;
            }
        }
        vector<int> odd(m), even(m);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even[i / 2] = i;
            } else {
                odd[i / 2] = i;
            }
        }
        sort(odd.begin(), odd.end(), [&](int i, int j){return a[i] < a[j];});
        sort(even.begin(), even.end(), [&](int i, int j){return a[i] < a[j];});
        if (offset == 1) {
            swap(odd, even);
        }
        vector<int> ans(n);
        int p = n;
        for (int x : even) {
            ans[x] = p--;
        }
        for (int x : odd) {
            ans[x] = p--;
        }
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
