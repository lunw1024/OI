#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        vector<vector<char>> mat(N, vector<char>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mat[i][j];
                if (i % 3 == 0)
                    mat[i][j] = 'X';
            }
            if (i > 0 && i % 3 == 0) {
                if (M == 1 || mat[i - 1][1] == '.' && mat[i - 2][1] == '.') {
                    mat[i - 1][0] = 'X';
                    mat[i - 2][0] = 'X';
                } else {
                    mat[i - 1][1] = 'X';
                    mat[i - 2][1] = 'X';
                }
            }
        }
        if (N % 3 == 0) {
            for (int i = 0; i < M; i++) {
                if (mat[N - 1][i] == 'X')
                    mat[N - 2][i] = 'X';
            }
        }
        for (vector<char> v : mat) {
            for (char c : v)
                cout << c;
            cout << endl;
        }
    }
}