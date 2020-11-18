#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1001;
int N, Q;
int bit[MAXN][MAXN];
bool mat[MAXN][MAXN];

inline int lowbit(int x) {
    return x & -x;
}

void update(int x, int y, int k) {
    while (x <= N) {
        int y1 = y;
        while (y1 <= N) {
            // update bit_y
            bit[x][y1] += k;
            y1 += lowbit(y1);
        }
        x += lowbit(x);
    }
}

int query(int x, int y) {
    int out = 0;
    while (x > 0) {
        int y1 = y;
        while (y1 > 0) {
            out += bit[x][y1];
            y1 -= lowbit(y1);
        }
        x -= lowbit(x);
    }
    return out;
}

int sum(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char ch;
            cin >> ch;
            mat[i][j] = ch == '*';
            if (mat[i][j])
                update(i, j, 1);
        }
    }

    for (int i = 1; i <= Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            mat[x][y] ^= 1;
            update(x, y, mat[x][y] ? 1 : -1);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << sum(x1, y1, x2, y2) << endl;
        }
    }
}