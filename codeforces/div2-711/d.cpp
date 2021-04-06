#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
const int MOD = int(1e5);

inline ll ceil(ll x, ll y) {
    return (x + y - 1) / y;
}

int main() {
    cin >> N >> M;
    vector<int> ans(M + 1, -1);
    ans[0] = 0;
    for (int i = 1; i <= N; i++) {
        int t, y;
        ll x;
        cin >> t >> x >> y;
        // cerr << "-- " << i << " --" << endl;
        if (t == 1) {
            for (int j = M; j >= 0; j--) {
                if (ans[j] >= 0) {
                    for (ll p = j + ceil(x, MOD), k = 1; p <= M && k <= y; p = p + ceil(x, MOD), k++) {
                        if (ans[p] == -1) {
                            ans[p] = i;
                            // cerr << j << " -> " << p << endl;
                        } else
                            break;
                    }
                }
            }
        } else if (t == 2) {
            for (int j = M; j >= 0; j--) {
                if (ans[j] >= 0) {
                    for (ll p = ceil(j * x, MOD), k = 1; p <= M && k <= y; p = ceil(p * x, MOD), k++) {
                        if (ans[p] == -1) {
                            ans[p] = i;
                            // cerr << j << " -> " << p << endl;
                        } else
                            break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= M; i++)
        cout << ans[i] << " ";
    cout << endl;
}