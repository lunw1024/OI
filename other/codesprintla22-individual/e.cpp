// shortest path

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int INF = int(1e9);
int N;
vector<string> S;
vector<vector<pair<int, int>>> edges;
vector<int> d;

int main() {
    cin >> N;
    edges.resize(N + 1);
    S.resize(N + 1);
    d.resize(N + 1, INF);
    for (int i = 0; i < N; i++) {
        cin >> S[i + 1];
    }
    
    for (int i = 1; i <= N; i++) {
        edges[0].push_back(make_pair(i, 0));
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            int k = 0;
            // TODO: use kmp
            while (k < min(S[i].size(), S[j].size()) && S[i][S[i].size() - k - 1] == S[j][k])
                k++;
            cerr << i << " " << j << ": " << k << endl;
            if (k > 0)
                edges[i].push_back(make_pair(j, -k));
        }
    }

    // bellman-ford
    d[0] = 0;
    bool flag = false;
    for (int i = 0; i <= N; i++) {
        flag = false;
        for (int u = 1; u <= N; u++) {
            if (d[u] == INF)
                continue;
            for (pair<int, int> e : edges[u]) {
                if (d[e.first] > d[u] + e.second) {
                    d[e.first] = d[u] + e.second;
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
    }
    if (flag) {
        cout << "Shakespeare, who?" << endl;
    } else {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans = min(ans, d[i]);
        }
        cout << -ans << endl;
    }
}
