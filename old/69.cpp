#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int MAXN = 1000000;
const int MOD = (int)1e9 + 7;
ll dp[MAXN];
ifstream fin("spainting.in");
ofstream fout("spainting.out");

int main()
{
    int N, M, K;
    fin >> N >> M >> K;
    dp[0] = 1;
    ll cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        if (i - K < 0)
        {
            dp[i] = (dp[i - 1] * M) % MOD;
        }
        else if (i - K == 0)
        {
            dp[i] = (dp[i - 1] * M - M) % MOD;
        }
        else
        {
            dp[i] = ((dp[i - 1] * M - dp[i - K] * (M - 1)) % MOD + MOD) % MOD;
        }
        
        cnt = (cnt * M) % MOD;
    }
    ll ans = ((cnt - dp[N]) % MOD + MOD) % MOD;
    fout << ans << endl;
    // system("pause");
}