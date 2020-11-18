#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N;

long long pow(long long a, long long x, long long mod)
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
    int a, b, c;
    cin >> a >> b >> c;
    cout << a << "^" << b << " mod " << c << "=" << pow(a, b, c) << endl;
    system("pause");
}