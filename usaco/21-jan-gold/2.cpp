#include <deque>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

const int INF = int(1e9);

int N, K;
vector<int> A;
vector<vector<bool>> edge;
vector<vector<pii>> graph;

int main() {
    cin >> N >> K;
    A.resize(N); edge.resize(K);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < K; i++) {
        edge[i].resize(K);
        for (int j = 0; j < K; j++) {
            char ch;
            cin >> ch;
            edge[i][j] = ch == '1';
        }
    }
    // node[i * K + k]: i-th position, can be received by class k
    // if A[i] == k: node[i, k] -> {node[i, j] | k -> j}
    graph.resize(N * K);
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < K; k++) {
            int idx = i * K + k;
            if (A[i] == k) {
                for (int j = 0; j < K; j++)
                    if (edge[k][j])
                        graph[idx].push_back(make_pair(i * K + j, 0));
            }
            if (i < N - 1)
                graph[idx].push_back(make_pair(idx + K, 1));
            if (i >= 1)
                graph[idx].push_back(make_pair(idx - K, 1));
        }
    }
    // bfs
    deque<pii> q;
    vector<int> dist(N * K, INF);
    for (int k = 0; k < K; k++) {
        if (edge[A[0]][k]) {
            dist[0 + k] = 0;
            q.push_front(make_pair(0 + k, 0));
        }
    }
    while (!q.empty()) {
        // cout << "hi" << endl;
        int idx = q.front().first, d = q.front().second;
        q.pop_front();
        if (dist[idx] < d)
            continue;
        for (pii e : graph[idx]) {
            if (dist[e.first] > dist[idx] + e.second) {
                dist[e.first] = dist[idx] + e.second;
                if (e.second == 0)
                    q.push_front(make_pair(e.first, dist[e.first]));
                else
                    q.push_back(make_pair(e.first, dist[e.first]));
            }
        }
    }
    cout << dist[(N - 1) * K + A[N - 1]];
}
