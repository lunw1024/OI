#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int MAXN = (int)1e5 + 1;
int N;
ll arr[MAXN];
ll ma[MAXN][17], mi[MAXN][17];
int mai[MAXN][17], mii[MAXN][17];

int solve(int l, int r) {
    if (r - l <= 0)
        return 0;
    if (r - l == 1) {
        return arr[l] < arr[r] ? 2 : 0;
    }
    int loglen = (int)log2(r - l + 1);
    int maxi = ma[l][loglen] >= ma[r - (1<<loglen) + 1][loglen] ? mai[l][loglen] : mai[r - (1<<loglen) + 1][loglen];
    int mini = mi[l][loglen] < mi[r - (1<<loglen) + 1][loglen] ? mii[l][loglen] : mii[r - (1<<loglen) + 1][loglen];
    int out = 0;
    if (mini < maxi) {
        out = max(max(out, maxi - mini + 1), max(solve(l, mini - 1), solve(maxi + 1, r)));
    } else {
        out = max(max(out, solve(l, maxi)), max(solve(maxi + 1, mini - 1), solve(mini + 1, r)));
    }
    return out;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ma[i][0] = arr[i], mi[i][0] = arr[i];
        mai[i][0] = i, mii[i][0] = i;
    }

    for (int k = 1; k < 17; k++) {
        for (int i = 0; i < N; i++) {
            int l = i, r = min(N - 1, i + (1 << k-1));
            if (ma[l][k - 1] >= ma[r][k - 1])
                ma[l][k] = ma[l][k - 1], mai[l][k] = mai[l][k - 1];
            else
                ma[l][k] = ma[r][k - 1], mai[l][k] = mai[r][k - 1];
            if (mi[l][k - 1] < mi[r][k - 1])
                mi[l][k] = mi[l][k - 1], mii[l][k] = mii[l][k - 1];
            else
                mi[l][k] = mi[r][k - 1], mii[l][k] = mii[r][k - 1];
        }
    }

    cout << solve(0, N - 1) << endl;
}