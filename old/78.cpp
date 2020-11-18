#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 100001;
int N, indegree[MAXN] = {0};
vector<int> edges[MAXN];
ifstream fin("deleg.in");
ofstream fout("deleg.out");

int dfs(int u, int parent, int k)
{
    multiset<int> s;
    for (int i = 0; i < edges[u].size(); i++)
    {
        if (edges[u][i] == parent)
            continue;

        int candidate = dfs(edges[u][i], u, k);
        if (candidate == -1)
            return -1;

        if (candidate == 0)
            continue;
        else if (s.count(k - candidate) >= 1)
            s.erase(s.find(k - candidate));
        else
            s.insert(candidate);
    }

    if (s.size() == 0)
        return 1;
    else if (s.size() == 1)
        return (1 + *s.begin()) % k;
    else
        return -1;
}

bool solve(int k)
{
    int result = dfs(1, 1, k);
    return result == 1;
}

int main()
{
    fin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        fin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        indegree[a]++;
        indegree[b]++;
    }
    if (N > 1)
    {
        for (int i = 1; i <= N - 1; i++)
        {
            if (i == 1)
                fout << 1;
            else if ((N - 1) % i == 0)
                fout << (solve(i) ? 1 : 0);
            else
                fout << 0;
        }
    }
    fout << endl;
}