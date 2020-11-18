#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 123456789;
int N, type;
int a[100001];

inline int lowbit(int x) {
    return x & -x;
}

ll cnt[200001], len[200001];

pair<int, ll> query(int x) {
    int l = 0;
    ll c = 1;
    while (x > 0) {
        if (len[x] > l)
            l = len[x], c = cnt[x];
        else if (len[x] == l)
            c = (c + cnt[x]) % MOD;
        x -= lowbit(x);
    }
    return make_pair(l, c);
}

void update(int x, int l, ll c) {
    while (x <= 200000) {
        if (len[x] == l) {
            cnt[x] = (cnt[x] + c) % MOD;
        } else if (len[x] < l) {
            len[x] = l;
            cnt[x] = c;
        }
        x += lowbit(x);
    }
}

int maxl = 0;
ll maxc = 1;

int main() {
    cin >> N >> type;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        pair<int, ll> p = query(a[i] - 1);
        int l = p.first + 1;
        ll c = p.second;
        if (maxl < l) {
            maxl = l, maxc = c;
        } else if (maxl == l) {
            maxc = (maxc + c) % MOD;
        }
        update(a[i], l, c);
    }
    
    cout << maxl << endl;
    if (type == 1)
        cout << maxc << endl;
}
