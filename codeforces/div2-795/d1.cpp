#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = -ll(1e18);
int N;
vector<ll> a, pre, f;

bool solve(int l, int r) {
    if (l + 1 == r)
        return true;
    ll mx = -INF, sum = 0;
    int argmax = -1;
    for (int i = l; i < r; i++) {
        sum += a[i];
        if (mx < a[i]) {
            argmax = i;
            mx = a[i];
        }
    }
    cerr << l << " " << r << " argmax=" << argmax << endl;
    if (mx < sum) {
        return false;
    } else {
        bool ans = true;
        if (argmax > l) {
            ans &= solve(l, argmax);
        }
        if (argmax + 1 < r) {
            ans &= solve(argmax + 1, r);
        }
        return ans;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        a.clear();
        a.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        cout << (solve(0, N) ? "YES" : "NO");
    }
}
