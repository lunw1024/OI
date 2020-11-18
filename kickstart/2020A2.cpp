#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int dp[51][1551];
int a[51][31];

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        int N, K, P;
        cin >> N >> K >> P;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= K; j++)
            {
                cin >> a[i][j];
                a[i][j] += a[i][j - 1];
            }
        }
        fill(&dp[0][0], &dp[N][P + 1], 0);

        // dp
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= P; j++)
            {
                for (int k = 0; k <= min(j, K); k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[i][k]);
                }
            }
        }

        cout << "Case #" << caseNo << ": " << dp[N][P] << endl;
    }
    // system("pause");
}
