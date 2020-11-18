#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, L;
ll K;
ll dp[11][2] = {0};
char ans[10] = {0};

int main()
{
    cin >> N >> L >> K;

    dp[0][0] = 1, dp[0][1] = 0;
    for (int l = 1; l <= L; l++)
    {
        dp[l][0] = dp[l - 1][0] * (N - 1);
        dp[l][1] = dp[l - 1][0] + dp[l - 1][1] * (N - 1); 
    }

    ll now = 0;
    bool flag = false;
    for (int l = 1; l <= L; l++)
    {
        for (int ch = 0; ch < (flag ? N - 1 : N); ch++)
        {
            if (!flag)
            {
                if (now + dp[L - l][1] + dp[L - l][0] >= K)
                {
                    ans[l-1] = 'A' + ch;
                    if (ch == N - 1)
                        flag = true;
                    break;
                }
                else
                {
                    now += dp[L - l][1] + dp[L - l][0];
                }

            }
            else
            {
                if (now + dp[L - l][0] >= K)
                {
                    ans[l-1] = 'A' + ch;
                    break;
                }
                else
                {
                    now += dp[L - l][0];
                }
            }
            
            
        }
    }

    for (int i = 0; i < L; i++)
        cout << ans[i];
    cout << endl;
    // system("pause");
}