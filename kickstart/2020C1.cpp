#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, Q;
ll BIT[2][(int)2e5 + 1];

inline int lowbit(int x) {
    return x & -x;
}

void add(int mode, int x, ll k) {
    while (x <= N) {
        BIT[mode][x] = BIT[mode][x] + k;
        x = x + lowbit(x);
    }
}

ll sum(int mode, int x) {
    ll out = 0;
    while (x > 0) {
        out += BIT[mode][x];
        x -= lowbit(x);
    }
    return out;
}

void change(int x, ll k) {
    // (-1)^(i-1) * a[i]
    ll new_ = (x % 2 * 2 - 1) * k ;
    add(0, x, new_ - sum(0, x) + sum(0, x - 1));

    // (-1)^(i-1) * i * a[i]
    new_ = (x % 2 * 2 - 1) * x * k;
    add(1, x, new_ - sum(1, x) + sum(1, x - 1));
}

ll query(int l, int r) {
    ll sign = (l % 2 * 2 - 1);
    ll a = sum(1, r) - sum(1, l - 1);
    ll b = sum(0, r) - sum(0, l - 1);
    return sign * (a - (l - 1) * b);
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        ll ans = 0;
        cin >> N >> Q;

        // clean
        fill(&BIT[0][0], &BIT[0][N], 0);
        fill(&BIT[1][0], &BIT[1][N], 0);
        
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            change(i, a);
        }

        // cout << "############" << endl;
        // for (int i = 1; i <= N; i++) {
        //     cout << sum(0, i) - sum(0, i - 1) << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= N; i++) {
        //     cout << sum(1, i) - sum(1, i - 1) << " ";
        // }
        // cout << endl << "############" << endl;
    
        for (int i = 1; i <= Q; i++) {
            char mode;
            cin >> mode;
            if (mode == 'Q') {
                int l, r;
                cin >> l >> r;
                ll res = query(l, r);
                ans += res;
            } else {
                int x, k;
                cin >> x >> k;
                change(x, (ll)k);
            }
            
        }

        cout << "Case #" << caseNo << ": " << ans << endl;
    }
}
