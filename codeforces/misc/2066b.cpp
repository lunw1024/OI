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
        vi a;
        int zeros = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            
            if (x == 0) {
                zeros++;
                if (zeros >= 2) {
                    continue;
                }
            }
            a.push_back(x);
            // cerr << x << " ";
        }
        // cerr << endl;
        vi premin(a.size(), int(1e9));
        premin[0] = a[0];
        for (int i = 1; i < a.size(); i++) {
            premin[i] = min(premin[i - 1], a[i]);
        }
        
        vector<bool> vis(n + 1);
        bool ok = true;
        int mex = 0;
        for (int i = int(a.size()) - 1; i >= 1; i--) {
            if (a[i] <= n) {
                vis[a[i]] = true;
            }
            while (vis[mex]) {
                mex++;
            }
            if (mex > premin[i - 1]) {
                ok = false;
                break;
            }
        }
        cout << (a.size() - !ok) << endl;

    }
}

