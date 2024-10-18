#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MOD = 998244353;

string merge(string a, string b) {
    int n = min(a.size(), b.size());
    vector<char> out;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            out.push_back(a[i]);
        } else if (a[i] == '?') {
            out.push_back(b[i]);
        } else if (b[i] == '?') {
            out.push_back(a[i]);
        } else {
            break;
        }
    }
    return string(out.begin(), out.end());
}

ll parse(string s) {
    ll ans = 0, a = 1;
    for (char c : s) {
        if (c == '?') {
            a = a * 26 % MOD;
        }
        ans = (ans + a);
    }
    return ans % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        cerr << "test case" << task << " / " << T << endl;
        int N;
        cin >> N;
        int L = 1 << N;
        vector<string> v(L);
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            v[1 << i] = s;
        }
        // cerr << "solve..." << endl;
        ll ans = 1;
        for (int i = 1; i < L; i++) {
            int lowb = i & (-i);
            int card = __builtin_popcount(i);
            // cerr << "card = " << card << endl;
            if (card == 1) {
              ans = (ans + parse(v[i])) % MOD;
              continue;
            }
            v[i] = merge(v[lowb], v[i ^ lowb]);
            // cerr << "merge " << endl;
            ans = (ans + parse(v[i]) * (card % 2 == 1 ? 1 : -1));
            // cerr << "parse " << endl;
            if (i % 1000000 == 0) {
                cerr << "running " << i << " / " << L << endl;
            }
        }
        ans = (ans + MOD) % MOD;
        cout << "Case #" << task << ": " << ans << endl;
    }
}
