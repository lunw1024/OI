#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        cin >> n >> k;
        map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            groups[x % k].emplace_back(x);
        }
        int odd_count = 0;
        for (auto& [id, v] : groups) {
            sort(v.begin(), v.end());
            odd_count += int(v.size()) % 2;
        }
        if (odd_count > 1) {
            cout << -1 << endl;
            continue;
        }
        ll ans = 0;
        for (auto& [id, v] : groups) {
            // cerr << "processing group " << id << ": ";
            // for (int x : v) {
            //     cerr << x << " ";
            // }
            // cerr << endl;
            if (v.size() % 2 == 0) {
                for (int i = 0; i < v.size(); i += 2) {
                    ans += (v[i + 1] - v[i]) / k;
                }
            } else {
                vector<ll> pre;
                pre.push_back(0);
                ll s = 0;
                for (int i = 2; i < v.size(); i += 2) {
                    s += (v[i - 1] - v[i - 2]) / k;
                    pre.emplace_back(s);
                }
                s = 0;
                ll res = ll(1e18);
                for (int i = int(v.size()) - 1; i >= 0; i -= 2) {
                    if (i + 2 < v.size()) {
                        s += (v[i + 2] - v[i + 1]) / k;
                    }
                    res = min(res, s + pre[i / 2]);
                }
                ans += res;
            }
            // cerr << "now ans = " << ans << endl;
        }
        cout << ans << endl;
    }
}

