#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int MAXN = 100001;
int N;

struct TreeArray
{
    int data[MAXN] = {0};

    int lowbit(int x)
    {
        return x & (-x);
    }

    int query(int pos)
    {
        int out = 0;
        while (pos > 0)
        {
            out += data[pos];
            pos -= lowbit(pos);
        }
        return out;
    }

    void update(int pos)
    {
        while (pos < MAXN)
        {
            data[pos] += 1;
            pos += lowbit(pos);
        }
    }
};

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

pair<ll, ll> arr[2][MAXN];
int newarr[2][MAXN];
int mapping[MAXN];
TreeArray tree;

int main()
{
    cin >> N;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j].first;
            arr[i][j].second = j;
        }
    }

    sort(&arr[0][1], &arr[0][N + 1]);
    sort(&arr[1][1], &arr[1][N + 1]);

    // sparse
    for (int i = 1; i <= N; i++)
    {
        newarr[0][arr[0][i].second] = i;
        newarr[1][arr[1][i].second] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        mapping[newarr[0][i]] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        newarr[1][i] = mapping[newarr[1][i]];
    }

    // compute reverse pairs
    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += tree.query(newarr[1][i]);
        ans %= 99999997;
        tree.update(newarr[1][i]);
    }
    cout << (1ll * N * (N-1) / 2 - ans) % 99999997 << endl;

    // system("pause");
}
