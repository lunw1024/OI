#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int N;
ll L, R;

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        cin >> N >> L >> R;
        int s = N, t = N;
        ll idx = 1;
        for (int i = N - 1; i >= 1; i--)
        {
            if (L >= idx + 2 * i)
                idx += 2 * i;
            else
            {
                s = N - i;
                break;
            }
        }
        ll temp = 1;
        for (int i = N - 1; i >= 1; i--)
        {
            if (R >= temp + 2 * i)
                temp += 2 * i;
            else
            {
                t = N - i;
                break;
            }
        }

        for (int i = s; i <= t; i++)
        {
            if (i == N)
            {
                cout << 1 << " ";
                break;
            }

            for (int j = 1; j <= 2 * (N - i); j++)
            {
                if (L <= idx && idx <= R)
                    cout << (idx % 2 == 1 ? i : i + j / 2) << " ";
                idx++;
            }
        }
        cout << endl;
    }
    // system("pause");
}