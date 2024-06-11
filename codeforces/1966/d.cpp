#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> gen(int n) {
    // all numbers < n
    int ub = 1;
    vector<int> res;
    while ((ub << 1) <= n) {
        res.push_back(ub);
        ub <<= 1;
    }
    if (ub != n) {
        res.push_back(n - ub);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        vector<int> ans = gen(k);
        ans.push_back(k + 1);
        ans.push_back(k + 2);
        // [k + 1, 3k + 2];
        int ub = 2 * k + 1;
        int lb = k + 1;
        while (ub < n) {
            ans.push_back(ub + 1 - lb);
            assert(ub + 1 - lb > k);
            ub = ub + ub + 1 - lb;
        }
        cout << ans.size() << endl;
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
