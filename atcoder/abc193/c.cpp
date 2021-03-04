#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pii = pair<int, int>;

ll N;
const double eps = 1e-7;

int main() {
    cin >> N;
    int rt = int(sqrt(N) + eps);
    ll ans = 0;
    vector<bool> vis(rt + 1);
    for (ll i = 2; i <= rt; i++) {
        if (vis[i])
            continue;
        for (ll j = i; j <= rt; j *= i) {
            vis[j] = true;
        }
        for (ll j = i * i; j <= N; j *= i) {
            ans++;
        }
    }
    cout << N - ans << endl;
}