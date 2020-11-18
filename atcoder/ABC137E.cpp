#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

int N, M, P;
vector<pair<int, int>> edges[2501];
int dist[2501] = {0};

int bellman_ford()
{
    fill(dist + 1, dist + 1 + N, 1e9);
    dist[1] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int u = 1; u <= N; u++)
        {
            for (pair<int, int> e : edges[u])
            {
                if (dist[u] < 1e9 && dist[e.first] > dist[u] + e.second)
                {
                    dist[e.first] = dist[u] + e.second;
                    // cout << "relax " << e.first << endl;
                }
            }
        }        
    }
    int prev = dist[N];
    for (int i = 1; i <= N; i++)
    {
        for (int u = 1; u <= N; u++)
        {
            for (pair<int, int> e : edges[u])
            {
                if (dist[e.first] < 1e9 && dist[e.first] > dist[u] + e.second)
                {
                    dist[e.first] = dist[u] + e.second;
                }
            }
        }
    }
    if (dist[N] < prev)
        return -1e9;
    return dist[N];
}

int main()
{
    cin >> N >> M >> P;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back(make_pair(b, P - c));
    }
    
    int ans = -bellman_ford();
    cout << (ans == (int)1e9 ? -1 : max(0, ans));
    // system("pause");
}