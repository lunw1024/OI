#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

ll N;

int main()
{
    cin >> N;
    ll temp = N - 1;
    ll ans = 1;
    for (ll i = 2; i * i <= N; i++)
    {
        int cnt = 0;
        while (temp % i == 0)
        {
            temp /= i;
            cnt++;
        }
        ans *= cnt + 1;
    }
    if (temp > 1)
        ans *= 2;

    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ll temp1 = N;
            while (temp1 % i == 0)
                temp1 /= i;
            
            if (temp1 % i == 1)
                ans++;

            temp1 = N;
            while (temp1 % (N / i) == 0)
                temp1 /= (N / i);
            
            if (temp1 % (N / i) == 1)
            {
                if (i * i != N)
                    ans++;
            }
        }
    }

    cout << ans << endl;
    // system("pause");
}