#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
ll N;
ll power[200001];

int main()
{
    cin >> N;
    power[0] = 1;
    for (int i = 1; i <= N; i++)
        power[i] = power[i - 1] * 10 % MOD;
    
    for (int i = 1; i <= N; i++)
    {
        ll ans = 0;
        if (i == N)
            ans = 10;
        else
            ans = ((N - i - 1) * 9 * 9 + 2 * 9 * 10) * power[N - i - 1] % MOD;
        cout << ans << " ";
    }
    // system("pause");
}