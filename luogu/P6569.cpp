#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 105;

struct Mat {
    int x, y;
    ll v[MAXN][MAXN];

    Mat(const int X = 0, const int Y = 0) : x(X), y(Y) {}

    Mat operator*(const Mat& o) const {
        if (y != o.x) {
            cout << "ERROR" << endl;
            exit(1);
        }
        Mat out(x, o.y);
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < o.y; j++) {
                out.v[i][j] = 0;
                for (int k = 0; k < y; k++) {
                    out.v[i][j] ^= v[i][k] * o.v[k][j];
                }
            }
        }
        return out;
    }
};

int N, M, Q;
Mat g[32], f;

int main() {
    cin >> N >> M >> Q;
    f.x = 1, f.y = N;
    for (int i = 0; i < 32; i++)
        g[i].x = g[i].y = N;
    for (int i = 0; i < N; i++)
        cin >> f.v[0][i];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[0].v[a][b] = g[0].v[b][a] = 1;
    }

    for (int i = 1; i < 32; i++)
        g[i] = g[i - 1] * g[i - 1];
    
    for (int i = 0; i < Q; i++) {
        ll a;
        cin >> a;
        Mat temp = f;
        for (int j = 0; a > 0; a >>= 1, j++) {
            if (a & 1) {
                temp = temp * g[j];
            }
        }
        cout << temp.v[0][0] << endl;
    }

}