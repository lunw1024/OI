#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 201;
int T, N, ans = 0;
int matchB[MAXN] = {0}, dfn[MAXN] = {0};
vector<int> edges[MAXN];

bool find(int x, int t)
{
    for (int i = 0; i < edges[x].size(); i++)
    {
        int y = edges[x][i];
        if (dfn[y] != t)
        {
            dfn[y] = t;
            if (matchB[y] == 0 || find(matchB[y], t))
            {
                matchB[y] = x;
                return true;
            }
        }
    }
    return false;
}

void hungary()
{
    fill(dfn, dfn + MAXN, 0);
    fill(matchB, matchB + MAXN, 0);
    for (int i = 1; i <= N; i++)
    {
        ans += find(i, i);
    }
}

int main()
{
    cin >> T;
    for (int case_ = 0; case_ < T; case_++)
    {
        cin >> N;
        ans = 0;
        for (int i = 1; i <= N; i++)
        {
            edges[i].clear();
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                int temp;
                cin >> temp;
                if (temp == 1)
                {
                    edges[i].push_back(j);
                }
            }
        }

        hungary();

        cout << (ans == N ? "Yes" : "No") << endl;
    }
    // system("pause");
}