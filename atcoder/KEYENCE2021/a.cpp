#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
using ll = long long;

int N;

int main() {
    cin >> N;
    vector<ll> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    ll mx = 0, prev = 0;
    for (int i = 0; i < N; i++) {
        mx = max(mx, a[i]);
        ll c = max(prev, b[i] * mx);
        cout << c << endl;
        prev = c;
    }
}