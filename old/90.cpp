#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int INF = 1e9 + 9;
int N;
int c[2001][2001], dist[2001];
bool vis[2001] = {0};
long long ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            cin >> c[i - 1][j];
            c[j][i - 1] = c[i - 1][j];
        }
    }

    fill(dist, dist + N + 1, INF);
    dist[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        dist[i] = min(dist[i], c[0][i]);
    }

    for (int i = 1; i <= N; i++)
    {
        int minimum = INF, idx = -1;
        for (int j = 1; j <= N; j++)
        {
            if (!vis[j] && dist[j] < minimum)
            {
                minimum = dist[j], idx = j;
            }
        }
        vis[idx] = true;
        ans += minimum;
        for (int j = 1; j <= N; j++)
        {
            if (dist[j] > c[idx][j])
            {
                dist[j] = c[idx][j];
            }
        }
        
        
    }
    cout << ans << endl;
    // system("pause");
}