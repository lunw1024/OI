#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

int N, K, benefit[(int)2e5 + 1];
vector<int> edges[(int)2e5 + 1];

int dfs(int u, int prev, int depth)
{
    int size = 0;
    for (int v : edges[u])
    {
        if (v == prev)
            continue;
        size += dfs(v, u, depth + 1);
    }
    benefit[u] = depth - size;
    return ++size;
}

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 1, 0);

    sort(benefit + 1, benefit + 1 + N, greater<int>());

    ll ans = 0;
    for (int i = 1; i <= K; i++)
        ans += benefit[i];
    cout << ans << endl;
    // system("pause");
}