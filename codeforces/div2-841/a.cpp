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
        ll s = 1;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            s *= x;
        }
        s = 2022 * (s + N - 1);
        cout << s << endl;

    }
}
