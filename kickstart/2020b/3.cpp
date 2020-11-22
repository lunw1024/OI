#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9;

inline const pair<ll, ll> operator+(const pair<ll, ll>&p1, const pair<ll, ll>&p2)
{
    pair<ll, ll> out;
    out.first = ((p1.first + p2.first) % MOD + MOD) % MOD;
    out.second = ((p1.second + p2.second) % MOD + MOD) % MOD;
    return out;
}

inline const pair<ll, ll> operator*(const ll factor, const pair<ll, ll>&p2)
{
    pair<ll, ll> out;
    out.first = ((factor * p2.first) % MOD + MOD) % MOD;
    out.second = ((factor * p2.second) % MOD + MOD) % MOD;
    return out;
}

string s;
int p;
pair<ll, ll> solve() {
    pair<ll, ll> out(0, 0);
    ll factor = 0;
    while (p < s.size()) {
        char ch = s[p];
        if (ch == 'N')
            p++, out = out + make_pair(0, -1);
        else if (ch == 'S')
            p++, out = out + make_pair(0, 1);
        else if (ch == 'E')
            p++, out = out + make_pair(1, 0);
        else if (ch == 'W')
            p++, out = out + make_pair(-1, 0);
        else if ('0' <= ch && ch <= '9') {
            p++;
            factor = (factor * 10 + ch - '0') % MOD;
        } else if (ch == '(') {
            p++;
            out = out + factor * solve();
            factor = 0;
        } else if (ch == ')') {
            p++;
            return out;
        }
    }
    return out;
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> s;
        p = 0;
        pair<ll, ll> ans = solve();
        cout << "Case #" << caseNo << ": " << ans.first + 1 << " " << ans.second + 1 << endl;
    }
}

