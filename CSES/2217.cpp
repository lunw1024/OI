#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi a(n), v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x - 1] = i;
        v[i] = x - 1;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ans++;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ans -= v[x] > 0 && a[v[x]] < a[v[x] - 1];
        ans -= v[y] > 0 && a[v[y]] < a[v[y] - 1];
        ans -= v[x] != v[y] - 1 && v[x] < n - 1 && a[v[x] + 1] < a[v[x]];
        ans -= v[y] != v[x] - 1 && v[y] < n - 1 && a[v[y] + 1] < a[v[y]];
        swap(a[v[x]], a[v[y]]);
        swap(v[x], v[y]);
        ans += v[x] > 0 && a[v[x]] < a[v[x] - 1];
        ans += v[y] > 0 && a[v[y]] < a[v[y] - 1];
        ans += v[x] != v[y] - 1 && v[x] < n - 1 && a[v[x] + 1] < a[v[x]];
        ans += v[y] != v[x] - 1 && v[y] < n - 1 && a[v[y] + 1] < a[v[y]];
        cout << ans << endl;
    }
}
// 3 1 2 5 4
