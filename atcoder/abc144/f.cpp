#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;

const int MAXN = 601;
int N, M;
double dp[MAXN], dp1[MAXN], ans = 1e9;
vector<int> edges[MAXN];

void do_dp(double (&dp)[MAXN], pair<int, int> ignore)
{
    fill(dp + 1, dp + N, 0);
    dp[N] = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j : edges[i])
        {
            if (i == ignore.first && j == ignore.second)
                continue;
            dp[i] += dp[j];
        }
        dp[i] = dp[i] / (edges[i].size() - (i == ignore.first ? 1 : 0)) + 1;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
    }

    do_dp(dp, make_pair(0, 0));
    ans = min(ans, dp[1]);
    // cout << "no block: ans = " << ans << endl;

    for (int i = 1; i < N; i++)
    {
        if (edges[i].size() == 1)
            continue;
        int argmax = 0;
        for (int j : edges[i])
        {
            if (dp[argmax] < dp[j])
                argmax = j;
        }
        do_dp(dp1, make_pair(i, argmax));
        // cout << "ignore " << i << " -> " << argmax << ": ans = " << dp1[1] << endl;
        ans = min(ans, dp1[1]);
    }
    cout << setiosflags(ios::fixed) << setprecision(9) << ans << endl;
    // system("pause");
}