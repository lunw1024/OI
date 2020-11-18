#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
using namespace std;

const int MAXN = 1000000;
int N;
string s;
int dp[MAXN][2];

int main()
{
    cin >> s;
    N = s.length();
    fill(&dp[0][0], &dp[MAXN - 1][2], (int)1e9);
    dp[N - 1][0] = s[N - 1] - '0', dp[N - 1][1] = 10 - (s[N - 1] - '0');
    for (int i = N - 2; i >= 0; i--)
    {
        int digit = s[i] - '0';
        dp[i][0] = min(dp[i + 1][0] + digit, dp[i + 1][1] + digit + 1);
        dp[i][1] = min(dp[i + 1][0] + 10 - (digit), dp[i + 1][1] + 10 - (digit + 1));
    }
    cout << min(dp[0][0], dp[0][1] + 1) << endl;
    // system("pause");
}