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
        int k, n;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt, starts;
        cnt.push_back(1);
        starts.push_back(0);
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt.back()++;
            } else {
                // cerr << "new start at" << i << endl;
                cnt.push_back(1);
                starts.push_back(i);
            }
        }
        // for (int x : cnt) {
        //     cout << x << " ";
        // }
        // cout << endl;
        int fails = 0;
        vector<int> idx;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] != k) {
                idx.push_back(i);
                fails++;
            }
        }
        int ans = -1;
        // cerr << "fails = " << fails << endl;
        if (fails == 0) {
            ans = n;
        } else if (fails == 1 && cnt[idx[0]] == 2 * k && idx[0] % 2 != (cnt.size() - 1) % 2) {
            ans = starts[idx[0]] + k; // sus
        } else if (fails == 2 && idx[1] == cnt.size() - 1) {
            // cerr << "idx0=" << idx[0] << ", idx1=" << idx[1] << endl;
            if (idx[0] % 2 == idx[1] % 2) {
                if (cnt[idx[0]] + cnt[idx[1]] == k) {
                    ans = starts[idx[0]] + cnt[idx[0]];
                } else if (cnt[idx[0]] + cnt[idx[1]] == 2 * k && cnt[idx[1]] < k) {
                    ans = starts[idx[0]] + cnt[idx[0]] - k;
                }
            }
        }
        cout << ans << endl;
    }
}

