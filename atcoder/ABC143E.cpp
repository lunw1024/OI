#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 301;
int N, M, Q;
ll L, dist1[MAXN][MAXN] = {0}, dist2[MAXN][MAXN] = {0};

void floyd(ll (&dist)[MAXN][MAXN])
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> L;
    fill(&dist1[0][0], &dist1[MAXN - 1][MAXN], (ll)1e18);
    for (int i = 1; i <= N; i++)
        dist1[i][i] = 0;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dist1[a][b] = c;
        dist1[b][a] = c;
    }

    floyd(dist1);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                dist2[i][j] = 0;
            else if (dist1[i][j] <= L)
                dist2[i][j] = 1;
            else
                dist2[i][j] = (ll)1e18;
        }
    }

    floyd(dist2);

    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (dist2[a][b] == (ll)1e18)
            cout << -1 << endl;
        else
            cout << dist2[a][b] - 1 << endl;
    }
}
