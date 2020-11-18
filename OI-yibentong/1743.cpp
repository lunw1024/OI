#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N;

struct BIT {
    ll v[200001];

    inline int lowbit(int x) {
        return x & -x;
    }

    void update(int x, ll k) {
        while (x <= N) {
            v[x] += k;
            x += lowbit(x);
        }
    }

    ll query(int x) {
        ll out = 0;
        while (x > 0) {
            out += v[x];
            x -= lowbit(x);
        }
        return out;
    }
};

int A[200001];
ll temp[200001], ans1, ans2;
BIT l, r;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++) {
        temp[i] = l.query(A[i] - 1);
        l.update(A[i], 1);
    }
    for (int i = N; i >= 1; i--) {
        ll a = r.query(N - A[i]);
        ans1 += temp[i] * a;
        ans2 += a * (a - 1) / 2;
        r.update(N + 1 - A[i], 1);
    }
    cout << ans2 - ans1 << endl;
}
