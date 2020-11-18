#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;

const ll INF = (ll)1e12;
int N, M, S, R;
vector<int> edges[301];
ll cost[301][301];
int recipe[301][4]; // fill with stone 0

void bfs_stone(int s) {
    queue<int> que;
    // init
    for (int i = 1; i <= N; i++) {
        if (cost[s][i] == 0)
            que.push(i);
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : edges[u]) {
            if (cost[s][v] == INF) {
                cost[s][v] = cost[s][u] + 1;
                que.push(v);
            }
        }
    }
}

void bfs_recipe(int r) {
    priority_queue<pii, vector<pii>, greater<pii>> que;
    int s = recipe[r][3];
    for (int i = 1; i <= N; i++) {
        if (cost[s][i] > cost[recipe[r][0]][i] + cost[recipe[r][1]][i] + cost[recipe[r][2]][i]) {
            cost[s][i] = cost[recipe[r][0]][i] + cost[recipe[r][1]][i] + cost[recipe[r][2]][i];
            que.push(make_pair(cost[s][i], i));
        }
        
    }
    while (!que.empty()) {
        pii top = que.top();
        que.pop();
        int u = top.second;
        if (top.first > cost[s][u])
            continue;
        for (int v : edges[u]) {
            if (cost[s][v] > cost[s][u] + 1) {
                cost[s][v] = cost[s][u] + 1;
                que.push(make_pair(cost[s][v], v));
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N >> M >> S >> R;
        for (int i = 1; i <= N; i++)
            edges[i].clear();
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= S; j++)    
                cost[j][i] = INF;

        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        for (int i = 1; i <= N; i++) {
            int C;
            cin >> C;
            for (int j = 0; j < C; j++) {
                int s;
                cin >> s;
                cost[s][i] = 0; // init mask
            }
        }

        for (int i = 1; i <= R; i++) {
            int K;
            cin >> K;
            for (int j = 0; j < 3; j++)
                recipe[i][j] = 0;
            for (int j = 0; j < K; j++)
                cin >> recipe[i][j];
            cin >> recipe[i][3];
        }
        
        for (int s = 1; s <= 300; s++) {
            bfs_stone(s);
        }

        // recipe
        for (int i = 1; i <= R; i++) {
            for (int r = 1; r <= R; r++) {
                bfs_recipe(r);
            }
        }

        // get ans
        ll ans = INF;
        for (int i = 1; i <= N; i++) {
            ans = min(ans, cost[1][i]);
        }
        cout << "Case #" << caseNo << ": " << ans << endl;
    }
}