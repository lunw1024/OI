#include <iostream>
#include <algorithm>
#include <vector>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    cin >> N;
    int ans = int(1e9);
    for (int i = 0; i < N; i++) {
        int a, p, x;
        cin >> a >> p >> x;
        if (x - a > 0)
            ans = min(ans, p);
    }
    cout << (ans == int(1e9) ? -1 : ans) << endl;
}