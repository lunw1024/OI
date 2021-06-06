#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int fa(int x) {
    return x >> 1;
}

int main() {
    int K, Q, N;
    cin >> K;
    N = 1 << K;
    vector<char> g(N);
    vector<int> f(N);
    for (int i = N - 1; i >= 1; i--) {
        cin >> g[i];
    }
    for (int i = N - 1; i >= 1; i--) {
        if (g[i] == '0') {
            f[i] = i * 2 < N ? f[i * 2] : 1;
        } else if (g[i] == '1') {
            f[i] = i * 2 < N ? f[i * 2 + 1] : 1;
        } else {
            f[i] = i * 2 < N ? f[i * 2] + f[i * 2 + 1] : 2;
        }
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int p;
        char c;
        cin >> p >> c;
        g[N - p] = c;
        for (int x = N - p; x > 0; x >>= 1) {
            if (g[x] == '0') {
                f[x] = x * 2 < N ? f[x * 2] : 1;
            } else if (g[x] == '1') {
                f[x] = x * 2 < N ? f[x * 2 + 1] : 1;
            } else {
                f[x] = x * 2 < N ? f[x * 2] + f[i * 2 + 1] : 2;
            }
        }
        cout << f[1] << endl;
    }
}
