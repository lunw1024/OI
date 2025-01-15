#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 2), pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[0] = 0;
    suf[n + 1] = static_cast<int>(1e9);
    for (int i = 1; i <= n; i++) {
        pre[i] = max(pre[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (pre[i] == a[i] && suf[i] == a[i]) {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << " ";
    int cnt = 0;
    for (int i : ans) {
        if (cnt >= 100) {
            break;
        }
        cout << i << " ";
        cnt++;
    }
    cout << endl;
}
