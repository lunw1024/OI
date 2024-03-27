#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> m;
int N;
vector<vector<bool>> vis;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool check(int x, int y) {
    return 0 <= x && x < 2 && 0 <= y && y < N;
}

bool dfs(int x, int y) {
    if (vis[x][y]) {
        return false;
    }
    vis[x][y] = true;
    if (x == 1 && y == N - 1) {
        return true;
    }
    bool out = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!check(nx, ny)) {
            continue;
        }
        if (nx == 1 && ny == N - 1) {
            return true;
        }
        if (m[nx][ny] == '<') {
            ny -= 1;
        } else if (m[nx][ny] == '>') {
            ny += 1;
        }
        out |= dfs(nx, ny);
    }
    return out;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        m.clear();
        m.resize(2, vector<char>(N));
        vis.clear();
        vis.resize(2, vector<bool>(N));
        for (int i = 0; i < N; i++) {
            cin >> m[0][i];
        }
        for (int i = 0; i < N; i++) {
            cin >> m[1][i];
        }
        bool ok = dfs(0, 0);
        cout << (ok ? "YES" : "NO") << endl;
    }
}
