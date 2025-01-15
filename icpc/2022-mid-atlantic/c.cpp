#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int dX[4] = {1, 0, -1, 0}, dY[4] = {0, 1, 0, -1};
const int INF = int(1e9);


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n + 2, vector<int>(m + 2, 0));
    queue<pii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                mat[i][j] = INF;
            }
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (mat[i][j] == 0) {
                q.push(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int u = x + dX[d], v = y + dY[d];
            if (u >= 0 && u <= n + 1 && v >= 0 && v <= m + 1) {
                if (mat[u][v] == INF) {
                    // cerr << u << v << endl;
                    mat[u][v] = mat[x][y] + 1;
                    q.push(make_pair(u, v));
                    ans = max(ans, mat[u][v]);
                }
            }
        }
    }
    cout << ans << endl;
}
