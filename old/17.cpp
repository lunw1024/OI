#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

int N, K;
ll ans = 1e9;
int data[200];
ll dp[200][8];
ifstream fin("cbarn2.in");
ofstream fout("cbarn2.out");

int main()
{
    fin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        fin >> data[i];
        data[N + i] = data[i];
    }

    for (int l = 0; l < N; l++)
    {
        // init
        fill(&dp[l][0], &dp[l + N - 1][8], 1e9);
        dp[l][1] = 0;

        for (int x = l + 1; x < l + N; x++)
        {
            for (int k = 2; k <= K; k++)
            {
                ll cost = 0, sum = 0;
                for (int i = 1; x - i >= l; i++)
                {
                    dp[x][k] = min(dp[x][k], dp[x - i][k - 1] + cost);
                    // cout << "l = " << l <<  " dp[" << x << "][" << k << "] = " << dp[x][k] << endl;
                    sum += data[x - i];
                    cost += sum;
                }
            }
        }

        ll cost = 0, sum = 0;
        for (int i = l + N - 1; i >= l; i--)
        {
            ans = min(ans, dp[i][K] + cost);
            sum += data[i];
            cost += sum;
        }
    }

    fout << ans << endl;
    // system("pause");
}