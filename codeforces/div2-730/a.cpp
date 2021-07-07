// x, x + d = d, x
// x = d * k

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (a == b)
            cout << "0 0" << endl;
        else if (a == 0) {
            cout << b << " 0" << endl;
        } else {
            ll dist = min(a % (b - a), (b - a) - a % (b - a));
            cout << (b - a) << " " << dist << endl;
        }
    }
}