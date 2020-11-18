#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = (int)2e3 + 1;
int N, M;
vector<pair<int, int>> edges[MAXN];
int dist[MAXN];

bool bellman_ford() {
    fill(dist + 1, dist + 1 + N, (int)1e9);
    dist[1] = 0;
    for (int i = 0; i < N; i++) {
        bool flag = false;
        for (int j = 1; j <= N; j++) {
            for (pair<int, int> p : edges[j]) {
                int k = p.first, w = p.second;
                if (dist[j] < (int)1e9 && dist[k] > dist[j] + w) {
                    dist[k] = dist[j] + w;
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
        if (i == N - 1 && flag)
            return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++) {
        cin >> N >> M;
        for (int i = 1; i <= M; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            edges[a].push_back(make_pair(b, w));
            if (w >= 0)
                edges[b].push_back(make_pair(a, w));
        }
        cout << (bellman_ford() ? "YES" : "NO") << endl;
        for (int i = 1; i <= N; i++)
            edges[i].clear();
    }
}