#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
const int INF = int(1e9);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        int K = 1 + floor(log2(min(N, M)));
        vector<vector<vector<int>>> st(N, vector<vector<int>>(M, vector<int>(K)));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> st[i][j][0];
            }
        }
        for (int k = 1; k < K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    int off = 1 << (k - 1);
                    int a = j - off >= 0 ? st[i][j - off][k - 1] : 0;
                    int b = i - off >= 0 ? st[i - off][j][k - 1] : 0;
                    int c = i - off >= 0 && j - off >= 0 ? st[i - off][j - off][k - 1] : 0;
                    st[i][j][k] = min(st[i][j][k - 1], min(a, min(b, c)));
                }
            }
        }
        int l = 1, r = min(N, M);
        while (l <= r) {
            int mid = (l + r) / 2;
            int ok = false;
            // cerr << "checking " << mid << endl;
            int k = floor(log2(mid));
            int off = mid - (1 << k);
            // cerr << k << ", " << off << endl;
            for (int i = mid - 1; i < N; i++) {
                for (int j = mid - 1; j < M; j++) {
                    if (min(st[i][j][k], min(st[i][j - off][k], min(st[i - off][j][k], st[i - off][j - off][k]))) >= mid) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    break;
                }
            }
            if (ok) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }

}
