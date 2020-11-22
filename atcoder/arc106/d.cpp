#include <atcoder/all>
#include <iostream>
using namespace atcoder;
using namespace std;
using mint = modint998244353;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    // preprocess
    vector<mint> fact(K + 1);
    fact[0] = 1;
    for (int i = 1; i <= K; i++) fact[i] = fact[i - 1] * i;

    vector<vector<mint>> pow(N + 1, vector<mint>(K + 1));
    for (int i = 1; i <= N; i++) pow[i][0] = 1;
    vector<mint> f(K + 1);
    f[0] = N;
    for (int k = 1; k <= K; k++) {
        for (int i = 1; i <= N; i++) {
            pow[i][k] = pow[i][k - 1] * arr[i];
            f[k] += pow[i][k];
        }
        f[k] /= fact[k];
    }

    // solve
    vector<mint> pow2(N + 1, 1);
    for (int x = 1; x <= K; x++) {
        mint S = 0;
        for (int k = 0; k <= x; k++) {
            S += f[k] * f[x - k];
        }
        S *= fact[x];
        // subtract (2a_i)^x
        for (int i = 1; i <= N; i++) {
            pow2[i] *= 2 * arr[i];
            S -= pow2[i];
        }
        S /= 2;
        cout << S.val() << endl;
    }
}