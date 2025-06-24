#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    const int maxd = 322;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<vector<ll>> pre(maxd + 1, vector<ll>(n + 1)), prei(maxd + 1, vector<ll>(n + 1));
        for (int d = 1; d <= maxd; d++) {
            for (int i = 1; i <= n; i++) {
                pre[d][i] = (i - d >= 0 ? pre[d][i - d] : 0) + a[i];
                prei[d][i] = (i - d >= 0 ? prei[d][i - d] : 0) + a[i] * ((i + d - 1) / d);
                // if (d == 3) {
                //     cerr << "prei[" << d << "][" << i << "] = " << prei[d][i] << endl;
                //     cerr << a[i] << " * " << ((i + d - 1)) << endl;
                    
                // }
            }
        }
        // cerr << "done preprocessing" << endl;
        for (int i = 0; i < q; i++) {
            int s, d, k;
            cin >> s >> d >> k;
            ll out = 0;
            if (d <= maxd) {
                ll rangei = prei[d][s + d * (k - 1)] - (s - d >= 0 ? prei[d][s - d]: 0);
                ll range = pre[d][s + d * (k - 1)] - (s - d >= 0 ? pre[d][s - d] : 0);
                // cerr << "d = " << d << endl;
                // for (int j = 1; j <= n; j += 1) {
                    // cerr << prei[d][j] << " ";
                // }
                // cerr << endl;
                // cerr << "rangei = " << rangei << endl;
                // cerr << "range = " << range << endl;
                out = rangei - ((s + d - 1) / d - 1) * range;
            } else {
                for (int j = 0; j < k; j++) {
                    out += (j + 1) * a[s + j * d];
                }
            }
            cout << out << " ";
        }
        cout << endl;
    }
}

