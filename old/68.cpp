#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int MAXN = 200000;
int N;
ll K;
ll arr[MAXN];

int solve(ll l1, ll r1, ll l2, ll r2, ll k, ll rk)
{
    while (l1 <= r1 && l2 <= r2)
    {
        ll mid1 = (l1 + r1) / 2, mid2 = (l2 + r2) / 2;
        if (mid1 * mid2 < K && r1 * r2 - mid1 * mid2 < rk)
        {

        }
    }
}

int main()
{
    cin >> N >> K;
    K *= 2;
    

}