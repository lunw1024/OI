#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int T, N, K, P[1000] = {0}, A[1000] = {0};
vector<int> dogs[1001];
int dp[1001][1001][2];

int main()
{
    cin >> T;
    for (int case_no = 1; case_no <= T; case_no++)
    {
        // init
        fill(&dp[0][0][0], &dp[1000][1000][2], (int)1e9);
        for (int i = 1; i <= 1000; i++)
        {
            dogs[i].clear();
        }

        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            cin >> P[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        for (int i = 0; i < N; i++)
        {
            dogs[A[i]].push_back(P[i]);
        }

        for (int i = 1; i <= 1000; i++)
        {
            dogs[i].push_back(0);
            sort(dogs[i].begin(), dogs[i].end());
        }

        // dp
        for (int i = 0; i <= 1000; i++)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = 0;
        }

        for (int color = 1; color <= 1000; color++)
        {
            for (int dognum = 1; dognum <= K; dognum++)
            {
                for (int i = 0; i < dogs[color].size(); i++)// take i dog of color color
                {
                    if (dognum - i < 0)
                    {
                        break;
                    }
                    dp[color][dognum][0] = min(dp[color][dognum][0], dp[color - 1][dognum - i][0] + 2 * dogs[color][i]);
                    dp[color][dognum][1] = min(dp[color][dognum][1], dp[color - 1][dognum - i][0] + dogs[color][i]);
                    dp[color][dognum][1] = min(dp[color][dognum][1], dp[color - 1][dognum - i][1] + 2 * dogs[color][i]);
                }
            }
        }

        cout << "Case #" << case_no << ": " << dp[1000][K][1] << endl;
        // for (int i = 0; i <= 1000; i++)
        // {
        //     for (int j = 0; j <= K; j++)
        //     {
        //         cout << dp[i][j][1] << " ";
        //     }
        //     cout << endl;
        // }
    }
    // system("pause");
}