#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 3001, MOD = 998244353;
int N, S;
ll A[MAXN];
ll f[MAXN][MAXN], g[MAXN][MAXN];
ll inv2 = 499122177;

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    ll pown = 1;
    for (int i = 1; i <= N; i++) {
        pown = pown * 2 % MOD;
    }

    // init
    for (int i = 0; i <= N; i++) {
        f[i][0] = pown;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            f[i][j] = f[i - 1][j] % MOD;
            if (A[i] <= j)
                f[i][j] = (f[i][j] + f[i - 1][j - A[i]] * inv2) % MOD;
        }
    }
    cout << f[N][S] << endl;
}
