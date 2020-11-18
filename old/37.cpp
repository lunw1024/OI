#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

struct BigInt
{
    const static int LEN = 100;
    int data[LEN] = {0};

    BigInt operator+(const BigInt& o) const
    {
        BigInt out;
        for (int i = 0; i < LEN - 1; i++)
        {
            out.data[i] += data[i] + o.data[i];
            out.data[i + 1] += out.data[i] / 10;
            out.data[i] %= 10;
        }
        return out;
    }

    BigInt operator*(const int o) const
    {
        BigInt out;
        for (int i = 0; i < LEN - 1; i++)
        {
            out.data[i] += data[i] * o;
            out.data[i + 1] += out.data[i] / 10;
            out.data[i] %= 10;
        }
        return out;
    }
};

const int MAXN = 101;
int N;
BigInt f[MAXN], g;

int main()
{
    cin >> N;
    f[1].data[0] = 1;
    f[0].data[0] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i] = f[i] + f[i - j] * j;
        }
    }
    for (int i = 2; i <= N; i++)
    {
        g = g + f[N - i] * (i * (i - 1));
    }
    BigInt ans = f[N] + g;
    bool flag = false;
    for (int i = ans.LEN - 1; i >= 0; i--)
    {
        if (ans.data[i] > 0)
        {
            flag = true;
        }
        if (flag)
        {
            cout << ans.data[i];
        }
    }
    cout << endl;
    // system("pause");
}
