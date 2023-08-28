#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vec1 = vector<char>;
using vec2 = vector<vector<char>>;

const int INF = int(1e9);
int N, M;

bool is_person(char c) {
    return c == '<' || c == '>' || c == '^' || c == 'v';
}

bool is_obstacle(char c) {
    return is_person(c) || c == '#';
}

bool is_passable(char c) {
    return c == 'S' || c == 'G' || c == '.';
}

pii get_dxdy(char c) {
    assert(is_person(c));
    if (c == 'v') {
        return make_pair(1, 0);
    } else if (c == '^') {
        return make_pair(-1, 0);
    } else if (c == '>') {
        return make_pair(0, 1);
    } else if (c == '<') {
        return make_pair(0, -1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    vec2 grid(N + 2, vec1(M + 2, '.'));
    vector<vector<int>> dist(N + 2, vector<int>(M + 2, INF));
    pii S, G;

    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
                grid[i][j] = '#';
                continue;
            }
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                S = make_pair(i, j);
            } else if (grid[i][j] == 'G') {
                G = make_pair(i, j);
            }
        }
    }
    // cout << "start processing people" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c = grid[i][j];
            if (is_person(c)) {
                pii dxdy = get_dxdy(c);
                int dx = dxdy.first, dy = dxdy.second;
                int x = i + dx, y = j + dy;
                while (!is_obstacle(grid[x][y])) {
                    assert(grid[x][y] == '.' || grid[x][y] == '!');
                    grid[x][y] = '!';
                    x += dx;
                    y += dy;
                }
            }
        }
    }
    // cout << "start bfs" << endl;
    // bfs
    queue<pii> q;
    q.push(S);
    dist[S.first][S.second] = 0;
    const vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_passable(grid[nx][ny]) && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    cout << (dist[G.first][G.second] == INF ? -1 : dist[G.first][G.second]) << endl;
}
