#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 101;
int M, N, ans = 0;
int matchA[MAXN] = {0}, matchB[MAXN] = {0}, dfn[MAXN] = {0};
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
                matchA[x] = y;
                matchB[y] = x;
                return true;
            }
        }
    }
    return false;
}

void hungary()
{
    for (int i = 1; i <= M; i++)
    {
        ans += find(i, i);
    }
}

int main()
{
    cin >> M >> N;
    int a, b;
    do
    {
        cin >> a >> b;
        edges[a].push_back(b);
    } while (a != -1 && b != -1);
    
    hungary();

    cout << ans << endl;
    for (int i = 1; i <= M; i++)
    {
        if (matchA[i] != 0)
        {
            cout << i << " " << matchA[i] << endl;
        }
    }
    // system("pause");
}