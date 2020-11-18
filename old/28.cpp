#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 20001;
int N, M;
int dfn[MAXN] = {0}, low[MAXN], time_ = 0;
bool ans[MAXN] = {0};
int cnt = 0;
vector<int> edges[MAXN];

void tarjan(int x, bool isroot)
{
    low[x] = dfn[x] = ++time_;
    int child = 0;
    for (vector<int>::iterator it = edges[x].begin(); it != edges[x].end(); it++)
    {
        if (dfn[*it] == 0)
        {
            child++;
            tarjan(*it, false);
            low[x] = min(low[x], low[*it]);
            if (!isroot && low[*it] >= dfn[x] && !ans[x])
            {
                ans[x] = true;
                cnt++;
            }
        }
        else
        {
            low[x] = min(low[x], dfn[*it]);
        }
        
    }
    if (isroot && child >= 2 && !ans[x])
    {
        ans[x] = true;
        cnt++;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i, true);
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= N; i++)
    {
        if (ans[i])
        {
            cout << i << endl;
        }
    }
    // system("pause");    
}