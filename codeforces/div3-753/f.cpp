#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<vector<int>> ans(2002, vector<int>(2002));
vector<vector<int>> dfn(2002, vector<int>(2002));
vector<vector<char>> mat(2002, vector<char>(2002, ' '));

pair<int, int> dfs(int x, int y, int d) {
    if (mat[x][y] == ' ') {
        return make_pair(0, 0);
    }
    if (ans[x][y] != 0) {
        return make_pair(0, ans[x][y]);
    }
    if (dfn[x][y] != 0) {
        ans[x][y] = d - dfn[x][y];
        return make_pair(d - dfn[x][y], ans[x][y]);
    }
    int dx = 0, dy = 0;
    char c = mat[x][y];
    if (c == 'D')
        dx = 1, dy = 0;
    if (c == 'U')
        dx = -1, dy = 0;
    if (c == 'R')
        dx = 0, dy = 1;
    if (c == 'L')
        dx = 0, dy = -1;
    dfn[x][y] = d;
    pair<int, int> res = dfs(x + dx, y + dy, d + 1);
    dfn[x][y] = 0;
    if (res.first == 0) {
        ans[x][y] = res.second + 1;
        return make_pair(0, ans[x][y]);
    } else {
        ans[x][y] = res.second;
        return make_pair(res.first - 1, ans[x][y]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++) {
            fill(ans[i].begin(), ans[i].begin() + m + 2, 0);
            fill(mat[i].begin(), mat[i].begin() + m + 2, ' ');
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mat[i][j];
            }
        }
        int d = 0, x = -1, y = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int res = dfs(i, j, 1).second;
                if (d < res) {
                    d = res;
                    x = i, y = j;
                }
            }
        }
        cout << x << " " << y << " " << d << "\n";
    }
    cout << endl;
}
