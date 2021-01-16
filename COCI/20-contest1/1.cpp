#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
char sea[100][100];
const int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
const char dir[4] = {'E', 'S', 'N', 'W'};
const int INF = (int)1e9;

int main() {
    cin >> N >> M;
    int sx, sy;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 'o')
                sx = i, sy = j;
        }
    }
    int ans[4] = {INF, INF, INF, INF};
    for (int d = 0; d < 4; d++) {
        int x = sx + dx[d], y = sy + dy[d], step = 0;
        while (sea[x][y] != 'o' && sea[x][y] != '.' && sea[x][y] != 'x') {
            if (sea[x][y] == '>')
                y++;
            else if (sea[x][y] == '<')
                y--;
            else if (sea[x][y] == 'v')
                x++;
            else if (sea[x][y] == '^')
                x--;
            step++;
        }
        if (sea[x][y] == 'x')
            ans[d] = step;
    }
    int minimum = INF, idx = -1;
    for (int i = 0; i < 4; i++) {
        if (minimum > ans[i])
            minimum = ans[i], idx = i;
    }
    cout << (minimum < INF ? ":)" : ":(") << endl;
    if (minimum < INF)
        cout << dir[idx] << endl;
}