#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

int N[3];
ll a[3][(int)1e5 + 1];
ll ans = (ll)2e18;

ll dist(ll a, ll b)
{
    return (a - b) * (a - b);
}

ll calc_ans(int i, int j, int k, int idxi, int idxj, int idxk)
{
    ll x = a[idxi][i], y = a[idxj][j], z = a[idxk][k];
    return dist(x, y) + dist(y, z) + dist(x, z);
}

int bin_search(int idx, double val)
{
    int l = 1, r = N[idx];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[idx][mid] < val - 0.001)
            l = mid + 1;
        else
            r = mid - 1;
    }
    l = min(l, N[idx]), r = max(r, 1);
    if (abs(a[idx][l] - val) < abs(a[idx][r] - val))
        return l;
    else
        return r;
}

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        cin >> N[0] >> N[1] >> N[2];
        for (int i = 0; i < 3; i++)
            for (int j = 1; j <= N[i]; j++)
                cin >> a[i][j];
        ans = (ll)2e18;

        sort(&a[0][1], &a[0][N[0] + 1]);
        sort(&a[1][1], &a[1][N[1] + 1]);
        sort(&a[2][1], &a[2][N[2] + 1]);

        for (int i = 1, j = 1; i <= N[0]; i++)
        {
            while (j < N[1] && dist(a[0][i], a[1][j + 1]) <= dist(a[0][i], a[1][j]))
                j++;
            int k = bin_search(2, (a[0][i] + a[1][j]) / 2.0);
            // cout << i << " " << j << " " << k << endl;
            ans = min(ans, calc_ans(i, j, k, 0, 1, 2));
        }
        for (int i = 1, j = 1; i <= N[1]; i++)
        {
            while (j < N[2] && dist(a[1][i], a[2][j + 1]) <= dist(a[1][i], a[2][j]))
                j++;
            int k = bin_search(0, (a[1][i] + a[2][j]) / 2.0);
            ans = min(ans, calc_ans(i, j, k, 1, 2, 0));
        }
        for (int i = 1, j = 1; i <= N[2]; i++)
        {
            while (j < N[0] && dist(a[2][i], a[0][j + 1]) <= dist(a[2][i], a[0][j]))
                j++;
            int k = bin_search(1, (a[2][i] + a[0][j]) / 2.0);
            ans = min(ans, calc_ans(i, j, k, 2, 0, 1));
        }

        cout << ans << endl;
    }
    // system("pause");


    
}