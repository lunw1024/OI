#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)1e6 + 1;
int N;
ll presum[MAXN];
ll ans = 0;
ll MAX;

struct BIT {
    ll data[MAXN];
    
    inline int lowbit(int x) {
        return x & -x;
    }
    
    ll presum(int x) {
        ll sum = 0;
        while (x > 0) {
            sum += data[x];
            x -= lowbit(x);
        }
        return sum;
    }

    void update(int x, ll k) {
        while (x <= MAX) {
            data[x] += k;
            x += lowbit(x);
        }
    }

    void clear() {
        fill(data + 1, data + 1 + MAX, 0);
    }
};

BIT zero, one;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> presum[i];
        presum[i] += presum[i - 1];
    }
    MAX = presum[N];
    for (int k = 0; (1 << k) <= presum[N]; k++) {
        zero.clear();
        one.clear();
        ll cnt = 0;
        for (int i = 0; i <= N; i++) {
            int tail = presum[i] % (1 << k);
            if ((presum[i] >> k) & 1) {
                cnt += zero.presum(tail + 1) + one.presum(presum[N]) - one.presum(tail + 1);
                one.update(tail + 1, 1);
            } else {
                cnt += one.presum(tail + 1) + zero.presum(presum[N]) - zero.presum(tail + 1);
                zero.update(tail + 1, 1);
            }
        }
        if (cnt % 2 == 1) {
            ans |= 1 << k;
        }
    }
    cout << ans << endl;
}
