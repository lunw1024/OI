#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int result = 0;
    if(t.substr(0, s.size()) == s) ++result;
    if(t.substr(m - s.size()) == s) result += 2;
    if (result == 0 || result == 3) cout << 3 - result;
    else cout << result;
}