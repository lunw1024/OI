#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Query
{
    int index;
    int l, r;
    int ans;
    Query(int index = 0, int l = 0, int r = 0)
    {
        this->index = index;
        this->l = l;
        this->r = r;
    }
};

int N, M;
int arr[1000001], tree[1000001] = {0}, next_[1000001] = {0}, prev_[1000001] = {0};
Query queries[1000001];

bool comp1(Query a, Query b)
{
    return a.l < b.l;
}

bool comp2(Query a, Query b)
{
    return a.index < b.index;
}

int lowbit(int x)
{
    return x & (-x);
}

int prefix_sum(int x)
{
    if (x == 0)
        return 0;
    int out = 0;
    while (x > 0)
    {
        out += tree[x];
        x -= lowbit(x);
    }
    return out;
}

int sum(int l, int r)
{
    return prefix_sum(r);
}

void change(int x, int k)
{
    while (x <= N)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        queries[i].index = i;
        cin >> queries[i].l >> queries[i].r;
    }
    sort(queries, queries + M, comp1);

    // preprocess
    for (int i = 1; i <= N; i++)
    {
        if (prev_[arr[i]] == 0)
        {
            change(i, 1);
        }
        else
        {
            next_[prev_[arr[i]]] = i;
        }
        prev_[arr[i]] = i;
    }
    int p = 0;
    for (int i = 1; i <= N; i++)
    {
        while (p < M && queries[p].l == i)
        {
            queries[p].ans = sum(queries[p].l, queries[p].r);
            p++;
        }
        // remove, add next
        change(i, -1);
        if (next_[i] > 0)
        {
            change(next_[i], 1);
        }
    }

    sort(queries, queries + M, comp2);

    for (int i = 0; i < M; i++)
    {
        cout << queries[i].ans << endl;
    }
    // system("pause");
}