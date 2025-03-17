#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int a = int(1e9), b = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
        
            a = min(a, x);
            b = max(b, x);
        }
        vector<int> ans;
        while (a < b) {
            if (a % 2 == b % 2) {
                ans.push_back(0);
                a /= 2;
                b /= 2;
            } else {
                if (a % 2 == 0) {
                    ans.push_back(0);
                    a /= 2;
                    b /= 2;
                } else {
                    ans.push_back(1);
                    a = (a + 1) / 2;
                    b = (b + 1) / 2;
                }
            }
        }
        cout << ans.size() << endl;
        if (!ans.empty() && ans.size() <= n) {
            for (int x : ans) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}

