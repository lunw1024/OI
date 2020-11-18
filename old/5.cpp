#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int T, N, P, S[100001] = {0};

int main()
{
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        cin >> N >> P;
        for (int i = 1; i <= N; i++)
        {
            cin >> S[i];
        }

        sort(S + 1, S + N + 1);

        int sum = 0, ans = 1e9;
        for (int i = 2; i <= N; i++)
        {
            if (i < P)
            {
                sum += (i - 1) * (S[i] - S[i - 1]);
            }
            else
            {
                if (i > P)
                {
                    sum -= S[i - 1] - S[i - P];                    
                }
                sum += (P - 1) * (S[i] - S[i - 1]);
                ans = min(ans, sum);
            }
            // cout << sum << endl;
        }
        cout << "Case #" << caseNo << ": " << ans << endl;
    }
    // system("pause");
}
