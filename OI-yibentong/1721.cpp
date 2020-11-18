#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 151, INF = (int)1e9;
int N, M, Q;
vector<pair<int, P> > edges;
int dp[MAXN][MAXN][MAXN] = {0};

int main() {
    cin >> N >> M >> Q;
    for (int i = 1; i <= M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(make_pair(w, make_pair(a, b)));
    }
    sort(edges.begin(), edges.end());

    // init
    fill(&dp[0][0][0], &dp[N][N][N + 1], INF);
    for (int i = 1; i <= N; i++) {
        dp[i][i][0] = 0;
    }

    // dp
    for (int e = 0; e < M; e++) {
        int w = edges[e].first, a = edges[e].second.first, b = edges[e].second.second;
        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= N; k++) {
                dp[i][b][k] = min(dp[i][b][k], dp[i][a][k - 1] + w);
            }
        }
    }

    // post process
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1]);
            }
        }
    }

    for (int q = 1; q <= Q; q++) {
        int a, b, c;
        cin >> a >> b >> c;
        c = min(c, N);
        cout << (dp[a][b][c] == INF ? -1 : dp[a][b][c]) << endl;
    }
    // system("pause");
}