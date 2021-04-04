#include <iostream>
#include <algorithm>
#include <atcoder/convolution>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

const int INF = int(1e9);

int N, M;
string s, a;

int main() {
    cin >> s >> a;
    reverse(a.begin(), a.end());
    N = s.size(), M = a.size();
    vector<int> s1(N), s2(N), a1(M), a2(M);
    for (int i = 0; i < N; i++) {
        s1[i] = s[i] == '1';
        s2[i] = 1 - s1[i];
    }
    for (int i = 0; i < M; i++) {
        a1[i] = a[i] == '1';
        a2[i] = 1 - a1[i];
    }
    int ans = INF;
    auto ans1 = convolution(s1, a2);
    auto ans2 = convolution(s2, a1);
    for (int i = M - 1; i < N; i++) {
        ans = min(ans, ans1[i] + ans2[i]);
    }
    cout << ans << endl;
}
