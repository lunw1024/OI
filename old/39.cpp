#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int MAXN = 101, MAXS = 10001;
ll S[MAXN], E[MAXN], L[MAXN];
ll dp[MAXS] = {0};

bool comp(int* a, int* b)
{
    return L[*a] * S[*b] > L[*b] * S[*a];
}

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        int N, sumS = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> S[i] >> E[i] >> L[i];
            sumS += S[i];
        }

        int* arr[MAXN];
        for (int i = 0; i < N; i++)
        {
            arr[i] = new int(i);
        }

        sort(arr, arr + N, comp);

        fill(dp, dp + sumS + 1, 0);

        for (int i = 0; i < N; i++)
        {
            int ii = *arr[i];
            for (int j = sumS; j >= 0; j--)
            {
                if (j >= S[ii])
                    dp[j] = max(dp[j - S[ii]] + max((ll)0, E[ii] - L[ii] * (j - S[ii])), dp[j]);
            }

        }
        ll ans = 0;
        for (int i = 0; i <= sumS; i++)
        {
            ans = max(ans, dp[i]);
        }
        cout << "case #" << caseNo << ": " << ans << endl;
    }
    // system("pause");
}