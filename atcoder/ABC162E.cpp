#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7, MAXN = 1e5 + 1;
int N, K, primecnt[MAXN] = {0};
bool is_prime[MAXN];
vector<int> primes;
ll ans = 0;

void Eratosthenes()
{
    for (int i = 0; i <= K; ++i)
        is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= K; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= K; j += i)
                is_prime[j] = 0;
        }
    }
}

long long qpow(long long a, long long b)
{
    a %= MOD;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    cin >> N >> K;

    Eratosthenes();

    for (int i = 1; i <= K; i++)
    {
        primecnt[i] = primecnt[i - 1] + is_prime[i];
    }

    for (int k = 1; k <= K; k++)
    {
        // cout << "k=" << k << endl;
        for (int i = 0; i < primes.size() && primes[i] <= K / k; i++)
        {
            // cout << primes[i] << " ";
            int range = log(K / k) / log(primes[i]);
            // cout << range << endl;
            ans = (ans + (qpow(range + 1, N) - qpow(range, N)) * k) % MOD;
        }
        if (K / k == 1)
            ans = (ans + k) % MOD;
    }
    
    cout << ans << endl;
    system("pause");
}