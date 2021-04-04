// the final function looks like:
//       _____
//      /
//_____/

#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = ll(1e18) / 4;
int N, Q;
ll x1 = -INF, x2 = INF, _y1 = -INF, y2 = INF;

ll eval(ll x) {
    if (x <= x1)
        return _y1;
    else if (x >= x2)
        return y2;
    else
        return _y1 + x - x1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a, t;
        cin >> a >> t;
        if (t == 1) {
            _y1 += a, y2 += a;
        } else if (t == 2) {
            x1 += max(_y1, a) - _y1;
            _y1 = max(_y1, a);
            x2 -= max(y2, _y1) - y2;
            y2 = max(y2, _y1);
        } else if (t == 3) {
            x2 -= y2 - min(y2, a);
            y2 = min(y2, a);
            x1 += _y1 - min(_y1, y2);
            _y1 = min(_y1, y2);
        }
        // sanity check
        cerr << x1 << " " << _y1 << " " << x2 << " " << y2 << endl;
        if (x2 - x1 != y2 - _y1)
            cerr << "ERROR!" << endl;
        if (x1 > x2 || _y1 > y2)
            cerr << "OH NO" << endl;
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << eval(x) << endl;
    }
}

