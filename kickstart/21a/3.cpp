#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using ll = long long;

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int R, C;

inline bool ok(int x, int y) {
    return 0 <= x && x < R && 0 <= y && y < C;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C;
        vector<vector<ll>> G(R, vector<ll>(C));
        vector<pair<ll, pii>> v;
        ll sum = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> G[i][j];
                sum += G[i][j];
                G[i][j] *= -1;
                v.push_back(make_pair(G[i][j], make_pair(i, j)));
            }
        }
        sort(v.begin(), v.end());
        queue<pii> que;
        que.push(v[0].second);
        int p = 1;
        while (v[p].first == v[p - 1].first)
            que.push(v[p++].second);
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            while (p < v.size() && G[x][y] == v[p].first - 1) {
                if (v[p].first == G[v[p].second.first][v[p].second.second])
                    que.push(v[p].second);
                p++;
            }
            for (int i = 0; i < 4; i++) {
                if (ok(x + dx[i], y + dy[i]) && G[x + dx[i]][y + dy[i]] > G[x][y] + 1) {
                    G[x + dx[i]][y + dy[i]] = G[x][y] + 1;
                    que.push(make_pair(x + dx[i], y + dy[i]));
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cerr << -G[i][j] << " ";
                ans += -G[i][j];
            }
            cerr << endl;
        }
        ans = ans - sum;
        cout << "Case #" << t << ": " << ans << endl;
    }
}