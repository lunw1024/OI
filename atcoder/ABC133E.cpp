#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
int N, K;
ll ans = 1, factorial[(int)1e5 + 1];
vector<int> edges[(int)1e5 + 1];

void dfs(int u, int prev, int depth)
{
    int childCnt = 0;
    for (int v : edges[u])
    {
        if (v != prev)
        {
            dfs(v, u, min(depth + 1, 2));
            ans = ans * (K - depth - childCnt) % MOD;
            childCnt++;
        }
    }
}

int main()
{
    cin >> N >> K;
    factorial[0] = 1;
    for (int i = 1; i <= N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    ans *= K;
    dfs(1, 1, 1);

    cout << ans << endl;
    // system("pause");
}
