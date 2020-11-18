#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1000002;
int N, M, R, cnt = 0, mapping[MAXN] = {0}, size_[MAXN] = {0}, seq[MAXN] = {0};
ll v[MAXN], BIT[2][MAXN] = {0};
vector<int> edges[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

ll psum(int x)
{
    int r = x;
    ll out = 0;
    while (x > 0)
    {
        out += BIT[0][x] * (r + 1) - BIT[1][x];
        x -= lowbit(x);
    }
    return out;
}

void add(int x, ll k)
{
    ll temp = x * k;
    while (x <= N)
    {
        BIT[0][x] += k;
        BIT[1][x] += temp;
        x += lowbit(x);
    }
}

int dfs(int u, int prev)
{
    cnt++;
    seq[cnt] = v[u];
    mapping[u] = cnt;
    for (int i = 0; i < edges[u].size(); i++)
    {
        int v = edges[u][i];
        if (v != prev)
        {
            size_[u] += dfs(v, u);
        }
    }
    size_[u]++;
    return size_[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> M >> R;

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(R, R);

    // build
    for (int i = 1; i <= N; i++)
    {
        add(i, seq[i] - seq[i - 1]);
    }

    for (int i = 1; i <= M; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, x;
            cin >> a >> x;
            add(mapping[a], x);
            add(mapping[a] + size_[a], -x);
        }
        else
        {
            int a;
            cin >> a;
            cout << psum(mapping[a] + size_[a] - 1) - psum(mapping[a] - 1) << endl;
        }
    }
    // system("pause");
}