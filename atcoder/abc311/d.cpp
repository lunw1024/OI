#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int dX[4] = {1, 0, -1, 0}, dY[4] = {0, 1, 0, -1};
int N, M;
vector<vector<bool>> grid, vis, mask;

pii get_tile(int x, int y, int d) {
    int dx = dX[d], dy = dY[d];
    mask[x][y] = true;
    while (grid[x + dx][y + dy]) {
        x = x + dx;
        y = y + dy;
        mask[x][y] = true;
    }
    return make_pair(x, y);
}

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int d = 0; d < 4; d++) {
        pii v = get_tile(x, y, d);
        int vx = v.first, vy = v.second;
        if (!vis[vx][vy]) {
            dfs(vx, vy);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    grid.resize(N, vector<bool>(M));
    vis.resize(N, vector<bool>(M));
    mask.resize(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;
            grid[i][j] = x == '.';
        }
    }
    dfs(1, 1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans += mask[i][j];
            // cout << (vis[i][j] ? "#" : " ");
        }
        // cout << endl;
    }
    cout << ans << endl;
}
