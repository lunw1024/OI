#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int INF = static_cast<int>(2e9);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vi a(n + 1), pre(n + 1);
        int p = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = a[i] + pre[i - 1];
            if (abs(a[i]) != 1) {
                p = i;
            }
        }
        int lb = 0, ub = 0;
        int x = 0, y = 0;
        for (int i = 1; i < p; i++) {
            x = min(x, pre[i]);
            y = max(y, pre[i]);
            ub = max(ub, pre[i] - x);
            lb = min(lb, pre[i] - y);
        }
        int plb = pre[p] - y, pub = pre[p] - x;
        int xx = pre[p], yy = pre[p];
        for (int i = p + 1; i <= n; i++) {
            xx = min(xx, pre[i]);
            yy = max(yy, pre[i]);
            ub = max(ub, pre[i] - xx);
            lb = min(lb, pre[i] - yy);
            pub = max(pub, pre[i] - x);
            plb = min(plb, pre[i] - y);
        }
        set<int> ans;
        // ans.insert(0);
        for (int i = lb; i <= ub; i++) {
            ans.insert(i);
        }
        for (int i = plb; i <= pub; i++) {
            ans.insert(i);
        }
        cout << ans.size() << endl;
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
}

