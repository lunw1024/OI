#include <iostream>
#include <algorithm>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll = long long;
using pii = pair<int, int>;
using mint = modint998244353;
using Mat = vector<vector<mint>>;

Mat operator*(const Mat a, const Mat b) {
    int N1 = a.size(), N2 = b[0].size(), N3 = b.size();
    Mat out(N1, vector<mint>(N2));
    for (int i = 0; i < N1; i++) {
        for (int j = 0; j < N2; j++) {
            for (int k = 0; k < N3; k++) {
                out[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return out;
}

Mat fast_exp(Mat a, ll b) {
    int N = a.size();
    Mat out(N, vector<mint>(N));
    for (int i = 0; i < N; i++)
        out[i][i] = 1;
    while (b > 0) {
        if (b & 1) {
            out = out * a;
        }
        b >>= 1;
        a = a * a;
    }
    return out;
}

void print(Mat a) {
    for (vector<mint> row : a) {
        for (mint e : row) {
            cout << e.val() << " ";
        }
        cout << endl;
    }
}

const int C[7] = {1, 1, 2, 3, 5, 8, 13};
ll H, W;

int main() {
    cin >> H >> W;
    int N = 1 << H;
    Mat A = Mat(N, vector<mint>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // ok?
            int coef = 1;
            for (int k = 1; k < N; k <<= 1) {
                if ((i & k) > 0 && (j & k) > 0) {
                    coef = 0;
                    break;
                }
            }

            // transfer
            for (int k = 1; k < N;) {
                int n = 0;
                while (k < N && (i & k) == 0 && (j & k) == 0) {
                    k <<= 1; n++;
                }
                if (n > 0) {
                    coef *= C[n];
                    continue;
                }
                k <<= 1;
            }

            A[j][i] = coef;
        }
    }
    // print(A);
    Mat x = Mat(N, vector<mint>(1));
    x[0][0] = 1;
    Mat ans = fast_exp(A, W) * x;
    cout << ans[0][0].val() << endl;
}
