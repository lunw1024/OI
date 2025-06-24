#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        a[i] = {j, i};
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    pii ans;
    while (l < r) {
        int y = a[l].first + a[r].first;
        if (x == y) {
            ans = {a[l].second + 1, a[r].second + 1};
            break;
        } else if (x < y) {
            r--;
        } else {
            l++;
        }
    }
    if (ans.first > 0) {
        cout << ans.first << " " << ans.second << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

