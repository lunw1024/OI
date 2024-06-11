#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> depth(n);
        int d = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                d++;
            } else {
                d--;
            }
            depth[i] = d;
        }
        map<int, int> cnt;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cnt[depth[i]];
            // vector<int> to_remove;
            // for (pair<int, int> x : cnt) {
            //     if (x.first < depth[i] - x.first) {
            //         to_remove.push_back(x.first);
            //     } else {
            //         break;
            //     }
            // }
            // for (int x : to_remove) {
            //     cnt.erase(x);
            // }
            cnt.erase(cnt.lower_bound(0), cnt.lower_bound(depth[i] / 2 + depth[i] % 2));
            cnt[depth[i]] += 1;
        }
        cout << ans << endl;
    }
}
