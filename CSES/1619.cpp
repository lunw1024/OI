#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pii> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, 1);
        a.emplace_back(r, -1);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int cnt = 0;
    for (auto [x, v] : a) {
        cnt += v;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

