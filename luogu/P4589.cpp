#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool connected[501][501], vis[1001];
int value[501], match[1001];
vector<int> edges[1001];

void floyd() {
    for (int k = 1; k <= M; k++)
        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= M; j++)
                connected[i][j] |= connected[i][k] && connected[k][j];
}

bool dfs(int u) {
    vis[u] = true;
    for (int v : edges[u]) {
        if (vis[v])
            continue;
        vis[v] = true;
        if (match[v] == 0 || dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

// returns max pair
int hungary() {
    int out = 0;
    fill(match + 1, match + 1 + 2 * M, 0);
    for (int i = 1; i <= 2 * M; i += 2) {
        fill(vis + 1, vis + 1 + 2 * M, false);
        if (dfs(i)) {
            out++;
        }
    }
    return out;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int n;
        cin >> value[i] >> n;
        for (int j = 1; j <= n; j++) {
            int v;
            cin >> v;
            connected[i][v] = true;
        }
    }
    floyd();

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= M; j++) {
            if (j == i || !connected[i][j]) 
                continue;
            edges[i * 2 - 1].push_back(j * 2);
        }
    }

    int result = max(1, M - hungary());
    if (result <= N + 1) {
        cout << "AK" << endl;
        return 0;
    }

    int l = 1, r = (int)1e9;
    while (l <= r) {
        int mid = (l + r) / 2, cnt = 0;
        for (int i = 1; i <= M * 2; i++)
            edges[i].clear();
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= M; j++) {
                if (i == j || value[i] >= mid || value[j] >= mid || !connected[i][j])
                    continue;
                edges[i * 2 - 1].push_back(j * 2);
            }
        }
        for (int i = 1; i <= M; i++)
            if (value[i] < mid)
                cnt++;
        int result = max(1, cnt - hungary());
        if (result <= N + 1) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
}