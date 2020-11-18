// http://ybt.ssoier.cn:8088/problem_show.php?pid=1725

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef pair<int, ll> P;

int N, M;
vector<P> edges[101];
ll dist[101];

bool bellman_ford() {
    // init
    fill(dist, dist + N + 1, 0);
    bool flag = true;
    for (int i = 0; i <= N; i++) {
        flag = true;
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k < edges[j].size(); k++) {
                int v = edges[j][k].first;
                ll w = edges[j][k].second;
                if (dist[v] > dist[j] + w) {
                    dist[v] = dist[j] + w;
                    flag = false;
                }
            }
        }
        if (flag)
            break;
    }
    
    return flag;
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N >> M;
        for (int i = 0; i <= N; i++) {
            edges[i].clear();
        }
        for (int i = 1; i <= M; i++) {
            int a, b;
            ll w;
            cin >> a >> b >> w;
            edges[a - 1].push_back(make_pair(b, w));
            edges[b].push_back(make_pair(a - 1, -w));
        }
        if (bellman_ford()) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
}
