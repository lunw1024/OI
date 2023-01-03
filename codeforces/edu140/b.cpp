#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
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
        int x = a[0];
        sort(a.begin(), a.end());
        for (int y : a) {
            if (y <= x) {
                continue;
            }
            x = int(ceil(double(x + y) / 2));
        }
        cout << x << endl;
    }
}
