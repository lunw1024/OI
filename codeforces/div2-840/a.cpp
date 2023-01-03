#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int mx = 0, mi = 1023;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            mx |= x;
            mi &= x;
        }
        cout << mx - mi << endl;
    }
}
