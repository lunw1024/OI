#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int T, N;
int a[23] = {0};
bool flag;

int cost()
{
    int out = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) > 1)
        {
            out++;
        }
    }
    return out;
}

bool mono()
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] != i + 1)
        {
            return false;
        }
    }
    return true;
}

void dfs(int depth, int maxDepth)
{
    if (flag || depth > maxDepth)
    {
        return;
    }
    
    if (mono())
    {
        flag = true;
        return;
    }

    if (depth + cost() > maxDepth)
    {
        return;
    }

    for (int i = 2; i <= N; i++)
    {
        reverse(a, a + i);
        dfs(depth + 1, maxDepth);
        reverse(a, a + i);
    }
}

int main()
{
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> N;
        flag = false;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }

        for (int maxDepth = 0; maxDepth <= 2 * N - 2; maxDepth++)
        {
            dfs(0, maxDepth);
            if (flag)
            {
                cout << maxDepth << endl;
                break;
            }
        }
    }
    // system("pause");
}