#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;

int K;
ll a[105] = {0}, ans = 0;
int main()
{
    char ch;
    int N = 0;
    while (true)
    {
        ch = cin.get();
        if (ch == '\n')
            break;
        a[N] = ch - '0';
        N++;
    }
    cin >> K;

    int not0[3] = {999, 999, 999}, p = 0;
    for (int i = 0; i < N; i++)
    {
        if (p < 3 && a[i] > 0)
        {
            not0[p] = i;
            p++;
        }
    }

    if (K == 1)
    {
        for (int i = 0; i < N; i++)
        {
            if (i <= 0)
                ans += a[i];
            else
                ans += 9;
        }
    }
    else if (K == 2)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (i <= not0[0] && j <= not0[1])
                {
                    ans += (a[i] - 1) * 9 + a[j];
                }
                else if (i <= not0[0])
                {
                    ans += a[i] * 9;
                }
                else
                {
                    ans += 81;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                for (int k = j + 1; k < N; k++)
                {
                    if (i <= not0[0] && j <= not0[1] && k <= not0[2])
                    {
                        ans += (a[i] - 1) * 81 + (a[j] - 1) * 9 + a[k];
                    }
                    else if (i <= not0[0] && j <= not0[1])
                    {
                        ans += (a[i] - 1) * 81 + a[j] * 9;
                    }
                    else if (i <= not0[0])
                    {
                        ans += a[i] * 81;
                    }
                    else
                    {
                        ans += 729;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    system("pause");
    
}