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
        cin >> k >> n;
        string s;
        cin >> s;
        vector<int> cnt;
        cnt.push_back(1);
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                cnt.back()++;
            } else {
                cnt.push_back(1);
            }
        }
        int fails = 0;
        vector<int> idx;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] != k) {
                idx.push_back(i);
                fails++;
            }
        }
        int ans = -1;
        if (fails == 0) {
            ans = n;
        } else if (fails == 2) {
            
        }
    }
}

