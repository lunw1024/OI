#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 100001;
int N, M, C;
vector<pair<int, int> > edges[MAXN];
int dist[MAXN] = {0}, indegree[MAXN] = {0};
ifstream fin("timeline.in");
ofstream fout("timeline.out");

void dfs(int u)
{
    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i].first, w = edges[u][i].second;
        dist[v] = max(dist[v], dist[u] + w);
        indegree[v]--;
        if (indegree[v] == 0)
        {
            dfs(v);
        }
    }
}

int main()
{
    fin >> N >> M >> C;
    for (int i = 1; i <= N; i++)
    {
        int w;
        fin >> w;
        edges[0].push_back(make_pair(i, w));
        indegree[i]++;
    }

    for (int i = 1; i <= C; i++)
    {
        int a, b, w;
        fin >> a >> b >> w;
        edges[a].push_back(make_pair(b, w));
        indegree[b]++;
    }

    dfs(0);

    for (int i = 1; i <= N; i++)
    {
        fout << dist[i] << endl;
    }
}