#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        string s, t;
        int ans = 0;
        cin >> s >> t;
        vector<int> p(26);
        for (int i = 0; i < 26; i++) {
            p[s[i] - 'a'] = i;
        }
        for (int i = 1; i < t.size(); i++) {
            ans += abs(p[t[i] - 'a'] - p[t[i - 1] - 'a']);
        }
        cout << ans << endl;
    }
}
