// LR substring cuts perm into sections
// if each section contains all values between [l, r] its fine
// keep track of the sections and the number of invalid sections.
// for each modification:
// split -> check each
// merge -> check new
// check using RMQ
// editorial has a simpler solution: maintain the bridge indices
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, q;
        cin >> n >> q;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            p--;
            d[min(i, p)] += 1;
            d[max(i, p)] -= 1;
        }
        for (int i = 1; i < n; i++) {
            d[i] += d[i - 1];
        }
        vector<char> a(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 && a[i - 1] == 'L' && a[i] == 'R') {
                cnt += d[i - 1] > 0;
            }
        }
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            x--;
            if (x > 0 && d[x - 1] > 0 && a[x - 1] == 'L') {
                cnt += (a[x] == 'L') - (a[x] == 'R');
            }
            if (x < n && d[x] > 0 && a[x + 1] == 'R') {
                cnt += (a[x] == 'R') - (a[x] == 'L');
            }
            a[x] = a[x] == 'L' ? 'R' : 'L';
            cout << (cnt == 0 ? "Yes" : "No") << endl;
        }
    }
}
