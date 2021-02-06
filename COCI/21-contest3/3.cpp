// Compare matrices with binary searching the first different element
// Use hash to compare same elements
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = (ll)1e9 + 7;
int N, M;
vector<ll> pow2, pow3;
vector<vector<ll>> h;
vector<vector<bool>> mat;

void preprocessing() {
    ll a = 1, b = 1;
    for (int i = 0; i <= 2 * N; i++) {
        pow2.push_back(a);
        a = a * 2 % MOD;
    }
    for (int i = 0; i <= 2 * M; i++) {
        pow3.push_back(b);
        b = b * 3 % MOD;
    }
    // make hash h(i, j) = a_ij * 2^i * 3^j
    h.resize(2 * N + 1);
    for (int i = 0; i <= 2 * N; i++)
        h[i].resize(2 * M + 1);
    for (int i = 1; i <= 2 * N; i++) {
        for (int j = 1; j <= 2 * M; j++) {
            h[i][j] = mat[i][j] * pow2[i] % MOD * pow3[j] % MOD;
            h[i][j] = (h[i][j] + h[i][j - 1]) % MOD;
        }
        for (int j = 1; j <= 2 * M; j++) {
            h[i][j] = (h[i][j] + h[i - 1][j]) % MOD;
        }
    }
}

ll get_hash(int x1, int y1, int x2, int y2) {
    return (h[x2][y2] - h[x1 - 1][y2] - h[x2][y1 - 1] + h[x1 - 1][y1 - 1]) % MOD;
}

bool comp(int x1, int y1, int x2, int y2) {
    int rl = 0, rr = N - 1;
    while (rl <= rr) {
        int mid = (rl + rr) / 2;
        ll hash1 = get_hash(x1, y1, x1 + mid, y1 + M - 1);
        ll hash2 = get_hash(x2, y2, x2 + mid, y2 + M - 1);
        if (hash2 * pow2[x1 - x2] % MOD * pow3[y1 - y2] % MOD == hash1)
            rl = mid + 1;
        else
            rr = mid - 1;
    }
    int dr = rl;
    if (dr == N)
        return false;
    int cl = 0, cr = M - 1;
    while (cl <= cr) {
        int mid = (cl + cr) / 2;
        ll hash1 = get_hash(x1 + dr, y1, x1 + dr, y1 + mid);
        ll hash2 = get_hash(x2 + dr, y2, x2 + dr, y2 + mid);
        if (hash2 * pow2[x1 - x2] % MOD * pow3[y1 - y2] % MOD == hash1)
            cl = mid + 1;
        else
            cr = mid - 1;
    }
    int dc = cl;
    if (dc == M)
        return false;
    // cout << "dr = " << dr << ", dc = " << dc << endl;
    return mat[x1 + dr][y1 + dc] < mat[x2 + dr][y2 + dc];
}

int main() {
    cin >> N >> M;
    mat.resize(2 * N + 1);
    for (int i = 0; i <= 2 * N; i++)
        mat[i].resize(2 * M + 1);
        
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char ch;
            cin >> ch;
            mat[i][j] = ch == '.';
            mat[i + N][j] = mat[i][j];
            mat[i][j + M] = mat[i][j];
            mat[i + N][j + M] = mat[i][j];
        }
    }
    preprocessing();
    int mx = 1, my = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (comp(i, j, mx, my)) {
                // cout << "(" << i << ", " << j << ") < (" << mx << ", " << my << ")" << endl;
                mx = i, my = j;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << (mat[mx + i][my + j] ? '.' : '*');
        }
        cout << endl;
    }
    // for (int i = 1; i <= 2 * N; i++) {
    //     for (int j = 1; j <= 2 * M; j++) {
    //         cout << h[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}