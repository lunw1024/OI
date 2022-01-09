#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = a[0];
        for (int i = 1; i < N; i++) {
            ans = max(ans, a[i] - a[i - 1]);
        }
        cout << ans << "\n";
    }
    cout << endl;
}
