#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 105, MAXM = 25;
int N, M, K, E;
vector<pair<ll, int> > edges[MAXM]; // (weight, id)
ll shortest_path[MAXN][MAXN]; // [j, i], i >= j
bool blocked[MAXM][MAXN] = {0};
bool temp[MAXM] = {0};// blocked
ll dp[MAXN];

ll dist[MAXM];
void dijkstra()
{
    // init
    fill(dist, dist + MAXM, (ll)1e9);
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > que;
    dist[1] = 0;
    que.push(make_pair(0, 1));

    while (!que.empty())
    {
        int id = que.top().second, dis = que.top().first;
        que.pop();
        if (dis != dist[id])
        {
            continue;
        }
        for (int i = 0; i < edges[id].size(); i++)
        {
            pair<ll, int> v = edges[id][i];
            if (!temp[v.second] && dist[v.second] > dis + v.first)
            {
                dist[v.second] = dis + v.first;
                que.push(make_pair(dist[v.second], v.second));
            }
        }
    }
}

void preprocess()
{
    for (int i = 1; i <= M; i++)
    {
        fill(temp, temp + MAXM, false);
        for (int j = i; j >= 1; j--)
        {
            for (int k = 1; k <= M; k++)
            {
                temp[k] = temp[k] || blocked[k][j];
            }

            dijkstra();

            shortest_path[i][j] = dist[M];
        }
    }
}

int main()
{
    cin >> N >> M >> K >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        edges[a].push_back(make_pair(l, b));
        edges[b].push_back(make_pair(l, a));
    }

    int d;
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        int p, l, r;
        cin >> p >> l >> r;
        for (int i = l; i <= r; i++)
        {
            blocked[p][i] = true;
        }
    }

    preprocess();

    // init
    fill(dp, dp + MAXN, (ll)1e9);
    dp[0] = -K;

    // dp
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (shortest_path[i][j] >= (ll)1e9)
                continue;
            dp[i] = min(dp[i], dp[j - 1] + shortest_path[i][j] * (i - j + 1) + K);
        }
    }

    cout << dp[N] << endl;
    // system("pause");
}
