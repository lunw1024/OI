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
        int n, m;
        cin >> n >> m;
        vi fib(n + 2);
        fib[0] = 1;
        fib[1] = 1;
        for (int i = 2; i <= n + 1; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        for (int i = 0; i < m; i++) {
            vi a(3);
            cin >> a[0] >> a[1] >> a[2];
            sort(a.begin(), a.end());
            if (a[2] >= fib[n + 1] && a[0] >= fib[n]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
}

