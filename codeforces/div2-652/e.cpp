#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAXN = (int)1e5 + 1, MAXM = (int)2e5 + 1;
int N, M;
int cnt[MAXN], indegree[MAXN];
vector<pair<int, int>> edges[MAXM];
queue<int> que;
stack<int> ans;
bool vis[MAXM];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> cnt[i];
    }
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(make_pair(b, i));
        edges[b].push_back(make_pair(a, i));
        indegree[a]++;
        indegree[b]++;
    }
    for (int i = 1; i <= N; i++) {
        if (indegree[i] <= cnt[i]) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto e : edges[u]) {
            int v = e.first, idx = e.second;
            if (!vis[idx]) {
                ans.push(idx);
                vis[idx] = true;
            }
            indegree[v]--;
            if (indegree[v] == cnt[v])
                que.push(v);
        }
    }
    
    if (ans.size() < M) {
        cout << "DEAD" << endl;
    } else {
        cout << "ALIVE" << endl;
        while (!ans.empty()) {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
}