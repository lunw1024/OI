#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 1, MOD = 998244353;
int N;
ll num[MAXN][4], pow2[MAXN];
pair<int, int> points[MAXN];

struct BIT
{
    int data[MAXN] = {0};
    
    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int x, int k)
    {
        while (x <= N)
        {
            data[x] += k;
            x += lowbit(x);
        }
    }

    int sum(int x)
    {
        int out = 0;
        while (x > 0)
        {
            out += data[x];
            x -= lowbit(x);
        }
        return out;
    }
};

inline ll mul(ll x, ll y)
{
    return x * y % MOD;
}

int main()
{
    cin >> N;
    pow2[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> points[i].first >> points[i].second;
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    // discretize y
    sort(points + 1, points + N + 1, [](pair<int, int> a, pair<int, int> b) -> bool { return a.second < b.second; });
    for (int i = 1; i <= N; i++)
    {
        points[i].second = i;
    }
    // discretize x
    sort(points + 1, points + N + 1);
    for (int i = 1; i <= N; i++)
    {
        points[i].first = i;
    }

    for (int mode = 0; mode <= 1; mode++)
    {
        BIT bit;
        for (int i = 1; i <= N; i++)
        {
            int a = bit.sum(points[i].second - 1), b = i - bit.sum(points[i].second) - 1;
            if (mode == 0)
            {
                num[i][0] = a;
                num[i][1] = b;
            }
            else
            {
                num[N + 1 - i][2] = b;
                num[N + 1 - i][3] = a;
            }
            bit.add(points[i].second, 1);
        }
        reverse(points + 1, points + 1 + N);
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = (ans + pow2[N - 1] + mul(mul(pow2[num[i][0]] - 1, pow2[num[i][2]] - 1), pow2[num[i][1] + num[i][3]])) % MOD;
        ans = (ans + mul(mul(pow2[num[i][1]] - 1, pow2[num[i][3]] - 1), pow2[num[i][0] + num[i][2]])) % MOD;
        ans = ((ans - mul(mul(pow2[num[i][0]] - 1, pow2[num[i][1]] - 1), mul(pow2[num[i][2]] - 1, pow2[num[i][3]] - 1))) % MOD + MOD) % MOD;
    }
    cout << ans << endl;
    // system("pause");
}