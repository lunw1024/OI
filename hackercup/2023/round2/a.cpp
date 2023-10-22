#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int R, C;
vector<vector<char>> board;
vector<vector<int>> cnt;
vector<vector<bool>> vis;
int group = 0;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

pii merge(pii a, pii b) {
    if (a.first == -3 || b.first == -3) {
        return {-3, -3};
    } else if (a.first == -2 || a.first == -1) {
        return b;
    } else if (b.first == -2 || b.first == -1) {
        return a;
    } else if (a != b) {
        return {-3, -3};
    } else {
        return a;
    }
}

pii dfs(int x, int y) {
    // cerr << "in (" << x << ", " << y << ")\n";
    if (board[x][y] != 'W') {
        return {-1, -1};
    }
    if (vis[x][y]) {
        return {-2, -2};
    }
    vis[x][y] = true;
    group++;
    pii ret = {-1, -1};
    for (int i = 0; i < 4; i++) {
        int u = x + dx[i], v = y + dy[i];
        if (board[u][v] == 'W') {
            pii a = dfs(u, v);
            ret = merge(ret, a);
        } else if (board[u][v] == '.') {
            // cerr << "air at (" << u << ", " << v << ")\n"; 
            ret = merge(ret, {u, v});
            // cerr << ret.first << ", " << ret.second << "\n";
        }
    }
    // cerr << "(" << x << ", " << y << ") returning " << ret.first << "-" << ret.second << "\n";
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> R >> C;
        board.resize(R + 2, vector<char>(C + 2));
        cnt.resize(R + 2, vector<int>(C + 2));
        vis.clear();
        vis.resize(R + 2, vector<bool>(C + 2));
        int ans = 0;
        for (int i = 0; i <= R + 1; i++) {
            for (int j = 0; j <= C + 1; j++) {
                if (i == 0 || j == 0 || i == R + 1 || j == C + 1) {
                    board[i][j] = 'B';
                } else {
                    cin >> board[i][j];
                }
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                group = 0;
                pii ret = dfs(i, j);
                // cout << ret.first << ", " << ret.second << endl;
                if (ret.first > -1) {
                    cnt[ret.first][ret.second] += group;
                    ans = max(ans, cnt[ret.first][ret.second]);
                }
            }
        }
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
}
