#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 1000;
int N;
vector<pair<int, int> > edges;
int x[MAXN], y[MAXN];
bool vis[MAXN];
ifstream fin("moocast.in");
ofstream fout("moocast.out");

inline int dist(int a, int b)
{
    return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

void dfs(int id, int k)
{
    vis[id] = true;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i] && dist(id, i) <= k)
        {
            dfs(i, k);
        }
    }
}

bool check(int k)
{
    fill(vis, vis + N, false);
    dfs(0, k);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            return false;
    }
    return true;
}

int main()
{
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        fin >> x[i] >> y[i];
    }
    
    int l = 0, r = 625000000;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    fout << l << endl;
    // system("pause");
}