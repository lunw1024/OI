#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 200000;
int next_[MAXN] = {0}, dp[MAXN] = {0}, N;
string s;

int main()
{
    cin >> s;
    N = s.length();

    next_[0] = 0;
    for (int i = 1; i < N; i++)
    {
        int p = next_[i - 1];
        while (p > 0 && s[i] != s[p])
        {
            p = next_[p - 1];
        }
        if (s[i] == s[p])
            p++;
        next_[i] = p;
    }

    int ans = N / 2;
    for (int i = 0; i < N; i++)
    {
        dp[i] = (next_[i] % 2 == 0 && next_[i] > 0);
        dp[i] += dp[next_[i] - 1];
        ans += dp[i];
        // cout << dp[i] << " ";
    }
    // cout << endl;
    cout << ans << endl;
    // system("pause");
}