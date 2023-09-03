#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    vector<int> a(N * 2);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    bitset<200000> b = 1;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < N * 2; i++) {
        b |= b << a[i];
        sum += a[i];
        if (b[i]) {
            ans = max(ans, sum - i);
            b[i] = false;
        }
    }
    cout << ans << endl;
}
