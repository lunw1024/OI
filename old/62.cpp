#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 202;
int N, L;
ll X[MAXN] = {0}, T[MAXN];// X[0] = 0, X[N + 1] = L;
ll dp[MAXN][MAXN][MAXN][2];

int main()
{
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i];
    }

    fill(&dp[0][0][0][0], &dp[N][N][N][2], (ll)1e17);
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    X[N + 1] = L;

    for (int l = 0; l <= N; l++)
    {
        for (int r = 0; r <= N - l; r++)
        {
            for (int k = 0; k <= l + r; k++)
            {
                // cout << l << " " << r << " " << k << endl;
                if (l > 0)
                {
                    if (k > 0 && dp[l - 1][r][k - 1][0] + X[l] - X[l - 1] <= T[l])
                        dp[l][r][k][0] = min(dp[l][r][k][0], dp[l - 1][r][k - 1][0] + X[l] - X[l - 1]);
                    dp[l][r][k][0] = min(dp[l][r][k][0], dp[l - 1][r][k][0] + X[l] - X[l - 1]);

                    if (k > 0 && dp[l - 1][r][k - 1][1] + X[l] + L - X[N + 1 - r] <= T[l])
                        dp[l][r][k][0] = min(dp[l][r][k][0], dp[l - 1][r][k - 1][1] + X[l] + L - X[N + 1 - r]);
                    dp[l][r][k][0] = min(dp[l][r][k][0], dp[l - 1][r][k][1] + X[l] + L - X[N + 1 - r]);
                }

                if (r > 0)
                {
                    if (k > 0 && dp[l][r - 1][k - 1][0] + X[l] + L - X[N + 1 - r] <= T[N + 1 - r])
                        dp[l][r][k][1] = min(dp[l][r][k][1], dp[l][r - 1][k - 1][0] + X[l] + L - X[N + 1 - r]);
                    dp[l][r][k][1] = min(dp[l][r][k][1], dp[l][r - 1][k][0] + X[l] + L - X[N + 1 - r]);

                    if (k > 0 && dp[l][r - 1][k - 1][1] + X[N + 1 - r + 1] - X[N + 1 - r] <= T[N + 1 - r])
                        dp[l][r][k][1] = min(dp[l][r][k][1], dp[l][r - 1][k - 1][1] + X[N + 1 - r + 1] - X[N + 1 - r]);
                    dp[l][r][k][1] = min(dp[l][r][k][1], dp[l][r - 1][k][1] + X[N + 1 - r + 1] - X[N + 1 - r]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++)
    {
        for (int k = 0; k <= N; k++)
        {
            for (int dir = 0; dir < 2; dir++)
            {
                if (dp[i][N - i][k][dir] < (ll)1e17)
                {
                    ans = max(ans, k);
                }
            }
        }
    }
    cout << ans << endl;
    // system("pause");
}