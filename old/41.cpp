#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 2; //(int)1e6 + 1;
int N, M;
int dp[MAXN][5][5] = {0};

inline int range(int l, int r)
{
    if (l == 0 && r == 2)
        return 0;
    else if (l == 1 && r == 2)
        return 1;
    else if (l == 1 && r == 3)
        return 2;
    else if (l == 2 && r == 3)
        return 3;
    else if (l == 2 && r == 4)
        return 4;
    else
        return -1;
}

int main()
{
    cin >> N >> M;
    string s;
    cin >> s;
    int a = 0, b = 1;

    // init
    int sum = 2, l = 2, r = 2;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'P' && range(min(l, sum - 1), max(r, sum - 1)) != -1) // change to L and init dp
        {
            dp[a][sum - 1][range(min(l, sum - 1), max(r, sum - 1))] += 1;
        }
        sum += s[i] == 'L' ? -1 : 1;
        l = min(l, sum);
        r = max(r, sum);

        if (i == N - 1)
        {
            break;
        }

        dp[b][0][0] = dp[a][1][0] + dp[a][1][1];
        dp[b][1][0] = dp[a][0][0] + dp[a][2][0];
        dp[b][2][0] = dp[a][1][0];

        dp[b][1][1] = dp[a][2][1];
        dp[b][2][1] = dp[a][1][1];
        
        dp[b][1][2] = dp[a][2][2] + dp[a][2][3];
        dp[b][2][2] = dp[a][1][2] + dp[a][3][2];
        dp[b][3][2] = dp[a][2][2] + dp[a][2][1];

        dp[b][2][3] = dp[a][3][3];
        dp[b][3][3] = dp[a][2][3];
       
        dp[b][2][4] = dp[a][3][4];
        dp[b][3][4] = dp[a][2][4] + dp[a][4][4];
        dp[b][4][4] = dp[a][3][4] + dp[a][3][3];


        dp[b][0][0] -= dp[b][0][0] >= M ? M : 0;
        dp[b][1][0] -= dp[b][1][0] >= M ? M : 0;
        dp[b][2][0] -= dp[b][2][0] >= M ? M : 0;
        dp[b][1][1] -= dp[b][1][1] >= M ? M : 0;
        dp[b][2][1] -= dp[b][2][1] >= M ? M : 0;
        dp[b][1][2] -= dp[b][1][2] >= M ? M : 0;
        dp[b][2][2] -= dp[b][2][2] >= M ? M : 0;
        dp[b][3][2] -= dp[b][3][2] >= M ? M : 0;
        dp[b][2][3] -= dp[b][2][3] >= M ? M : 0;
        dp[b][3][3] -= dp[b][3][3] >= M ? M : 0;
        dp[b][2][4] -= dp[b][2][4] >= M ? M : 0;
        dp[b][3][4] -= dp[b][3][4] >= M ? M : 0;
        dp[b][4][4] -= dp[b][4][4] >= M ? M : 0;

        swap(a, b);

    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            ans += dp[a][i][j];
        }
    }
    cout << (ans + 1) % M << endl;
    // system("pause");
}