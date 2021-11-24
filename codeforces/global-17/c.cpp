// f[i][r] = in first i people the maximum subset s.t. we can take at most r - f[i][r] more ppl from the right
// f[i][r] <- f[i-1][r]
// f[i][r] <- max(f[i-1][r'] | r' >= r) + 1 (this is actually useless), because f[i][r] is decreasing by r
// f[i][r'] <- f[i-1][r'] + 1 (r' < r)
// i increasing, r decreasing so good
// roll the first dimension
// O(N)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = int(1e9);

struct BIT {
    int n;
    vector<int> data;
    BIT(int n) {
        this->n = n;
        data.resize(n);
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    int query(int x) {
        int out = 0;
        while (x > 0) {
            out += data[x];
            x -= lowbit(x);
        }
        return out;
    }
    void add(int x, int k) {
        while (x < n) {
            data[x] += k;
            x += lowbit(x);
        }
    }
};

int N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        BIT bit = BIT(N * 2 + 1);
        int off = 1;
        for (int i = 0; i < N; i++) {
            int l, r;
            cin >> l >> r;
            bit.add()
        }
        
    }
}