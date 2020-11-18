#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N;
long long hash_[2][10000] = {0};
const int MOD[2] = {(int)1e9 + 7, (int)1e9 + 9};

long long power(long long a, long long x, long long mod)
{
    int out = 1, unit = a;
    while (x > 0)
    {
        if (x & 1)
        {
            out = out * unit % mod;
        }
        unit = unit * unit % mod;
        x >>= 1;
    }
    return out;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            hash_[0][i] = s[j] * power(128, j, MOD[0]) % MOD[0];
            hash_[1][i] = s[j] * power(128, j, MOD[1]) % MOD[1];
        }
    }

    sort(&hash_[0][0], &hash_[0][0] + N);
    int size = unique(&hash_[0][0], &hash_[0][0] + N) - &hash_[0][0];// or define comp() and enumerate

    cout << size << endl;
    // system("pause");
}