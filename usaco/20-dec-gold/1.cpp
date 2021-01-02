#include <iostream>
#include <atcoder/all>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using namespace atcoder;
using pii = pair<int, int>;

const int INF = (int)1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int N, D;

bool legal(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    cin >> N >> D;
    vector<vector<char>> S(N, vector<char>(N));
    vector<vector<int>> dp(N, vector<int>(N, INF));
    vector<vector<int>> dist(N, vector<int>(N, INF));
    queue<pii> que;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
            if (S[i][j] == '#') {
                que.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }

    // compute nearest wall
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (legal(nx, ny) && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push(make_pair(nx, ny));
            }
        }
    }

    // BFS
    vector<vector<pii>> srcs(N / 2 + 1, vector<pii>());
    vector<vector<bool>> ans(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'S') {
                que.push(make_pair(i, j));
                dp[i][j] = 0;
                srcs[dist[i][j]].push_back(make_pair(i, j));
                ans[i][j] = true;
            }
        }
    }
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (legal(nx, ny) && dp[nx][ny] == INF && dist[nx][ny] > dp[x][y] / D) {
                dp[nx][ny] = dp[x][y] + 1;
                que.push(make_pair(nx, ny));
                srcs[dist[nx][ny]].push_back(make_pair(nx, ny));
                ans[nx][ny] = true;
            }
        }
    }
    
    // BFS for answer
    queue<pii> nxt;
    for (int d = N / 2; d >= 1; d--) { // current radius
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (legal(nx, ny) && S[nx][ny] != '#' && !ans[nx][ny]) {
                    ans[nx][ny] = true;
                    nxt.push(make_pair(nx, ny));
                }
            }
        }
            
        for (pii e : srcs[d]) {
            nxt.push(make_pair(e.first, e.second));
        }
        swap(que, nxt);
    }

    int out = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            out += ans[i][j];
        } 
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // cout << (dp[i][j] == INF ? -1 : dp[i][j]) << " ";
            cout << ans[i][j]; 
        }
        cout << endl;
    }

    for (int d = N / 2; d >= 1; d--) {
        cout << d << ": " << endl;
        for (pii e : srcs[d])
            cout << e.first << " " << e.second << endl;
    }
    cout << out << endl;
}

