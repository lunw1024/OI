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
    int n;
    cin >> n;
    vector<pii> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(r, l);
    }
    sort(a.begin(), a.end());
    int t = 0;
    int ans = 0;
    for (auto [r, l] : a) {
        if (l < t) {
            continue;
        }
        t = r;
        ans++;
    }
    cout << ans << endl;
}

