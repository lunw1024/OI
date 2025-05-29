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
    vector<int> a(1000001);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] += 1;
    }
    int ans = 1;
    for (int i = 2; i <= 1000000; i++) {
        int cnt = 0;
        for (int j = i; j <= 1000000; j += i) {
            cnt += a[j];
            if (cnt >= 2) {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
}

