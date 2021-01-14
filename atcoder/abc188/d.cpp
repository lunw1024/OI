#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int N;
    ll C;
    cin >> N >> C;
    vector<pair<int, ll>> arr;
    for (int i = 0; i < N; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        arr.push_back(make_pair(a, c));
        arr.push_back(make_pair(b + 1, -c));
    }
    sort(arr.begin(), arr.end());
    ll sum = 0, ans = 0;
    int last = 0;
    for (pair<int, ll> e : arr) {
        int t = e.first;
        ll c = e.second;
        ans += min(C, sum) * (t - last);
        sum += c;
        last = t;
    }
    cout << ans << endl;
}