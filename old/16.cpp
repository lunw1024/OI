#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long phi(long long x)
{
    long long out = x;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            out = out / i * (i - 1);
            while (x % i == 0)
            {
                x /= i;
            }
        }
    }
    if (x > 1)
        out = out / x * (x - 1);
    return out;
}

long long power(long long a, long long x, long long mod)
{
    long long out = 1;
    while (x > 0)
    {
        if (x & 1)
        {
            out = out * a % mod;
        }
        x >>= 1;
        a = a * a % mod;
    }
    return out % mod;
}

int main()
{
    long long a, m, b = 0;
    cin >> a >> m;
    string s;
    cin >> s;
    long long phm = phi(m);
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        b = b * 10 + s[i] - '0';
        if (b >= phm)
        {
            flag = true;
            b %= phm;
        }
    }
    if (flag)
    {
        b += phm;
    }
    cout << power(a, b, m) << endl;
    // system("pause");
}