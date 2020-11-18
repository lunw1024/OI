#include <iostream>
using namespace std;

long long createTree(int x);
long long sum(int low, int high, int x);
void add(int low, int high, long long k, int x);

long long l[100001 * 4] = {0};
long long r[100001 * 4] = {0};
long long lazy[100001 * 4] = {0};
long long v[100001 * 4] = {0};
long long a[100001] = {0};
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    l[1] = 1;
    r[1] = n;
    createTree(1);
    for (int i = 0; i < m; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, y;
            long long k;
            cin >> x >> y >> k;
            add(x, y, k, 1);
        }
        else if (type == 2)
        {
            int x, y;
            cin >> x >> y;
            cout << sum(x, y, 1) << endl;
        }
    }
}

long long createTree(int x)
{
    if (l[x] < r[x])
    {
        int mid = (r[x] + l[x]) / 2;
        l[2 * x] = l[x];
        r[2 * x] = mid;
        createTree(2 * x);
        l[2 * x + 1] = mid + 1;
        r[2 * x + 1] = r[x];
        createTree(2 * x + 1);
        v[x] = v[2 * x] + v[2 * x + 1];
    }
    else // is leaf
    {
        v[x] = a[l[x]];
    }
}

long long sum(int low, int high, int x)
{
    if (l[x] < r[x] && lazy[x] > 0)
    {
        v[2 * x] += lazy[x] * (r[2 * x] - l[2 * x] + 1);
        lazy[2 * x] += lazy[x];
        v[2 * x + 1] += lazy[x] * (r[2 * x + 1] - l[2 * x + 1] + 1);
        lazy[2 * x + 1] += lazy[x];
        lazy[x] = 0;
    }

    if (low == l[x] && high == r[x])
    {
        return v[x];
    }

    int mid = (l[x] + r[x]) / 2;
    if (low <= mid && high <= mid)
    {
        return sum(low, high, 2 * x);
    }
    else if (low <= mid && high > mid)
    {
        return sum(low, mid, 2 * x) + sum(mid + 1, high, 2 * x + 1);
    }
    else if (low > mid && high > mid)
    {
        return sum(low, high, 2 * x + 1);
    }
}

void add(int low, int high, long long k, int x)
{
    if (low == l[x] && high == r[x])
    {
        v[x] += k * (high - low + 1);
        lazy[x] += k;
        return;
    }

    int mid = (l[x] + r[x]) / 2;
    v[x] += k * (high - low + 1);// add self
    if (low <= mid && high <= mid)
    {
        add(low, high, k, 2 * x);
    }
    else if (low <= mid && high > mid)
    {
        add(low, mid, k, 2 * x);
        add(mid + 1, high, k, 2 * x + 1);
    }
    else if (low > mid && high > mid)
    {
        add(low, high, k, 2 * x + 1);
    }
}