#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, q;
        cin >> n >> q;
        vi a(n + 1);
        set<int> ones;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                ones.insert(i);
            }
            sum += a[i];
        }
        for (int i = 0; i < q; i++) {
            int op;
            cin >> op;
            if (op == 1) {
                int s;
                cin >> s;
                int l = n + 1, r = 0;
                if (!ones.empty()) {
                    l = *(ones.begin());
                    r = *(ones.rbegin());
                }
                int m = min(l - 1, n - r);
                if (s > sum || s % 2 != sum % 2 && sum - s < m * 2) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
                
            } else {
                int idx, v;
                cin >> idx >> v;
                sum -= a[idx];
                ones.erase(idx);
                if (v == 1) {
                    ones.insert(idx);
                }
                sum += v;
                a[idx] = v;
            }
        }
    }
}

