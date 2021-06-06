#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int o = 0, e = 0;
        vector<int> v;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            if (x % 2 == 0) {
                e++;
            } else {
                o++;
                v.push_back(x);
            }
        }
        int ans = e * (e - 1) / 2 + e * o;
        for (int i = 0; i < o; i++) {
            for (int j = i + 1; j < o; j++) {
                 ans += gcd(v[i], v[j]) > 1;
            }
        }
        cout << ans << endl;
    }
}
