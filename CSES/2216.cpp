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
    vi a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x - 1] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}

