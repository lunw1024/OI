// islands -> remove
// p(p(i)) != i => must move some shit
// each op == changing 1 edge
// want all self loops or 2-cycles
// since degree = 1, there can only be simple cycles
// 2-cycles strictly better? 1 op to clear 1-2 vertices
// bounded by (n - # self cycles) / 2? no
// wait this graph is not just deg 1
// it is a permutation i.e. a set of cycles
// so for n-cycle bounded by ceil(n/2). Its exactly ceil(n/2)
// i misread. swapping ops is more effective.
// one ops will split f(n) into f(2) + f(n-2)
// 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x - 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            int p = i, cnt = 1;
            vis[p] = true;
            while (a[p] != i) {
                p = a[p];
                vis[p] = true;
                cnt++;
            }
            ans += cnt > 2 ? (cnt + 1) / 2 - 1 : 0;
        }
        cout << ans << endl;
    }
}
