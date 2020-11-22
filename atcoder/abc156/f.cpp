#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int K, Q;
ll D[5000];

int main() {
    cin >> K >> Q;
    for (int i = 0; i < K; i++) {
        cin >> D[i];
    }
    
    for (int t = 0; t < Q; t++) {
        int n;
        ll x, m;
        cin >> n >> x >> m;
        x %= m;
        int q = (n - 1) / K, r = (n - 1) % K;
        int cnt = 0;
        for (int i = 0; i < min(K, n - 1); i++) {
            int coef = i < r ? q + 1 : q;
            x += D[i] % m * coef;
            if (D[i] % m == 0)
                cnt += coef;
        }
        cout << n - 1 - x/m - cnt << endl;
    }
}