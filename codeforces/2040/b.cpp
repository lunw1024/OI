#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int x = 1, ans = 1;
        while (x < n) {
            x = 2 * (x + 1);
            ans++;
        }
        cout << ans << endl;
    }
}

