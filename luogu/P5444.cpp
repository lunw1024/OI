#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll A, B, C;
vector<pair<ll, ll>> arr;

int main() {
    cin >> N >> A >> B;
    if ((double)A / __gcd(A, B + 1) * B > 2e18)
        C = (ll)2e18;
    else
        C = A / __gcd(A, B + 1) * B;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        a %= C;
        b %= C;
        if (a > b) {
            arr.push_back(make_pair(a, C - 1));
            arr.push_back(make_pair(0, b));
        } else {
            arr.push_back(make_pair(a, b));
        }
    }
    arr.push_back(make_pair(C, C));
    sort(arr.begin(), arr.end());
    ll l = arr[0].first, r = arr[0].second, ans = 0;
    for (pair<ll, ll> e : arr) {
        if (r < e.first) {
            ans += r - l + 1;
            l = e.first;
            r = e.second;
        }
        else
            r = max(r, e.second);
    }
    cout << ans << endl;
}