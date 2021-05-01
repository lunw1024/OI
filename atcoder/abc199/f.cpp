// matrix fast exponentiation
#include <iostream>
#include <algorithm>
#include <vector>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using ll = long long;
using pii = pair<int, int>;
using Mat = vector<vector<mint>>;

int N, M, K;
Mat x, A;

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

Mat fast_exp(Mat a, int b) {
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

void show(Mat a) {
    for (vector<mint> row : a) {
        for (mint e : row) {
            cout << e.val() << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> N >> M >> K;
    x.resize(N, vector<mint>(1)); A.resize(N, vector<mint>(N));
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        x[i][0] = temp;
        A[i][i] = 2 * M;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        A[a][b] = 1;
        A[b][a] = 1;
        A[a][a] -= 1;
        A[b][b] -= 1;
    }
    
    A = fast_exp(A, K);
    mint coef = mint(2 * M).pow(K).inv();
    Mat ans = A * x;
    for (vector<mint>& row : ans) {
        for (mint& e : row) {
            e *= coef;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i][0].val() << endl;
    }
}