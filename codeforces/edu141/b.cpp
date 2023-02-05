#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int f(int x) {
    return x % 2 == 1 ? (x + 1) / 2 : N * N + 1 - x / 2;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<vector<int>> m(N, vector<int>(N));
        int cur = 1;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < N; j++) {
                    m[i][j] = f(cur++);
                }
            } else {
                for (int j = N - 1; j >= 0; j--) {
                    m[i][j] = f(cur++);
                }
            }
        }
        for (vector<int>& a : m) {
            for (int x : a) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
