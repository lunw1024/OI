#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int h;
    cin >> h;
    vi c(h + 1);
    int n = 0;
    for (int i = 0; i <= h; i++) {
        cin >> c[i];
        n += c[i];
    }
    int idx = -1;
    for (int i = 1; i <= h; i++) {
        if (c[i] > 1 && c[i - 1] > 1) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "perfect" << endl;
        return 0;
    }
    vi ans(n + 1);
    for (int i = 1; i <= h + 1; i++) {
        ans[i] = i - 1;
    }
    int alt = -1, child = -1;;
    int cnt = h + 1;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < c[i] - 1; j++) {
            ans[++cnt] = i;
            if (i == idx - 1) {
                alt = cnt;
            }
            if (i == idx) {
                child = cnt;
            }
        }
    }
    cout << "ambiguous" << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    ans[child] = alt;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

