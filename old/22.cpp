#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef long long ll;

ll MOD;

struct SegmentTree
{
    ll data[500001], add[500001], mul[500001];
    int size;
    ll* source;

    inline int ls(int x)
    {
        return x << 1;
    }

    inline int rs(int x)
    {
        return x << 1 | 1;
    }

    void build(int l, int r, int p)
    {
        if (l == r)
        {
            data[p] = source[l] % MOD;
            return;
        }
        
        int mid = (l + r) / 2;
        build(l, mid, ls(p));
        build(mid + 1, r, rs(p));
        data[p] = (data[ls(p)] + data[rs(p)]) % MOD;
    }

    SegmentTree(ll* source, int size)
    {
        this->size = size;
        this->source = source;
        fill(add + 1, add + size + 1, 0);
        fill(mul + 1, mul + size + 1, 1);
        build(1, size, 1);
    }

    void push_down(int l, int r, int p)
    {
        if (l == r)
            return;
        int mid = (l + r) / 2;

        // left son
        data[ls(p)] = (data[ls(p)] * mul[p] + (mid-l+1) * add[p]) % MOD;
        mul[ls(p)] = mul[ls(p)] * mul[p] % MOD;
        add[ls(p)] = (add[ls(p)] * mul[p] + add[p]) % MOD; 
        // right son
        data[rs(p)] = (data[rs(p)] * mul[p] + (r-mid) * add[p]) % MOD;
        mul[rs(p)] = mul[rs(p)] * mul[p] % MOD;
        add[rs(p)] = (add[rs(p)] * mul[p] + add[p]) % MOD;

        mul[p] = 1;
        add[p] = 0;
    }

    void update_add(int nl, int nr, ll value, int l, int r, int p)
    {
        push_down(l, r, p);
        if (nl <= l && r <= nr)
        {
            data[p] = (data[p] + value * (r - l + 1)) % MOD;
            add[p] = (add[p] + value) % MOD;
            return;
        }

        int mid = (l + r) / 2;
        if (nl <= mid)
        {
            update_add(nl, nr, value, l, mid, ls(p));
        }
        if (mid + 1 <= nr)
        {
            update_add(nl, nr, value, mid + 1, r, rs(p));
        }
        data[p] = (data[ls(p)] + data[rs(p)]) % MOD;
    }

    void update_mul(int nl, int nr, ll value, int l, int r, int p)
    {
        push_down(l, r, p);
        if (nl <= l && r <= nr)
        {
            data[p] = (data[p] * value) % MOD;
            mul[p] = (mul[p] * value) % MOD;
            add[p] = add[p] * value % MOD;
            return;
        }

        int mid = (l + r) / 2;
        if (nl <= mid)
        {
            update_mul(nl, nr, value, l, mid, ls(p));
        }
        if (mid + 1 <= nr)
        {
            update_mul(nl, nr, value, mid + 1, r, rs(p));
        }
        data[p] = (data[ls(p)] + data[rs(p)]) % MOD;
    }

    ll query(int nl, int nr, int l, int r, int p)
    {
        push_down(l, r, p);
        if (nl <= l && r <= nr)
        {
            return data[p];
        }

        ll out = 0;
        int mid = (l + r) / 2;
        if (nl <= mid)
        {
            out += query(nl, nr, l, mid, ls(p));
        }
        if (mid + 1 <= nr)
        {
            out += query(nl, nr, mid + 1, r, rs(p));
        }
        return out % MOD;
    }
};

int N, M;
ll arr[100001];
SegmentTree* tree;

void print()
{
    for (int i = 1; i <= N; i++)
    {
        cout << tree->query(i, i, 1, N, 1) << " ";
    }
    cout << endl;
}

int main()
{
    cin >> N >> M >> MOD;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    tree = new SegmentTree(arr, N);

    for (int i = 0; i < M; i++)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
        {
            ll k;
            cin >> k;
            tree->update_mul(x, y, k, 1, N, 1);
        }
        else if (type == 2)
        {
            ll k;
            cin >> k;
            tree->update_add(x, y, k, 1, N, 1);
        }
        else
        {
            cout << (tree->query(x, y, 1, N, 1) + MOD) % MOD << endl;
        }
        print();
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << tree->query(i, i, 1, N, 1) << endl;
    // }
    // system("pause");
}