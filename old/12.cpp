#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

int N, M;
ll arr[100001], sum[400001], tag[400001] = {0};

inline int ls(int x)
{
    return x << 1;
}

inline int rs(int x)
{
    return x << 1 | 1;
}

void push_down(int x, int l, int r)// push down a single layer
{
    int mid = (l + r) / 2;
    sum[ls(x)] += (mid - l + 1) * tag[x];
    sum[rs(x)] += (r - mid) * tag[x];
    tag[ls(x)] += tag[x];
    tag[rs(x)] += tag[x];
    tag[x] = 0;
}

void add(int x, int l, int r, int nl, int nr, ll k)// nl, nr, k is constant
{
    if (nl <= l && r <= nr)// contain
    {
        sum[x] += (r - l + 1) * k;
        tag[x] += k;
        return;
    }

    push_down(x, l, r);
    int mid = (l + r) / 2;
    if (nl <= mid)// left not empty
    {
        add(ls(x), l, mid, nl, nr, k);
    }
    if (mid + 1 <= nr)// right not empty
    {
        add(rs(x), mid + 1, r, nl, nr, k);
    }
    sum[x] = sum[ls(x)] + sum[rs(x)];
}

ll query(int x, int l, int r, int nl, int nr)// generally same as add()
{
    ll out = 0;
    if (nl <= l && r <= nr)
    {
        return sum[x];
    }
    
    push_down(x, l, r);
    int mid = (l + r) / 2;
    if (nl <= mid)
    {
        out += query(ls(x), l, mid, nl, nr);
    }
    if (mid + 1 <= nr)
    {
        out += query(rs(x), mid + 1, r, nl, nr);
    }
    return out;
}

void init(int x, int l, int r)
{
    if (l == r)
    {
        sum[x] = arr[l];
        return;
    }
    else
    {
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        sum[x] = sum[ls(x)] + sum[rs(x)];
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    init(1, 1, N);
    for (int i = 0; i < M; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int nl, nr, k;
            cin >> nl >> nr >> k;
            add(1, 1, N, nl, nr, k);
        }
        else
        {
            int nl, nr;
            cin >> nl >> nr;
            cout << query(1, 1, N, nl, nr) << endl;
        }
    }
    // system("pause");
}