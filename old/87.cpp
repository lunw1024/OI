#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;

ll inv[200001];
ll N, P;
ll f[20000] = {0};
ll ans = 0;

inline ll qpow(ll a, ll b)
{
    ll ans = 1;
    a = (a % P + P) % P;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = (a * ans) % P;
        a = (a * a) % P;
    }
    return ans;
}

int main()
{
    string s;
    cin >> N >> P >> s;

    // preprocess
    inv[0] = 1;
    inv[1] = qpow(10, P - 2);
    for (int i = 2; i < N; i++)
    {
        inv[i] = inv[i - 1] * inv[1] % P;
    }
    ll offset = 0;
    for (int i = 0; i < N; i++)
    {
        ll d = s[i] - '0';
        ans += f[(((P - d) * inv[i] - offset) % P + P) % P];
        if (d % P == 0)
            ans++;
        f[(P - offset) % P]++;
        // cout << (P - offset) % P << "++" << endl;
        offset = (offset + d * inv[i]) % P;
    }
    cout << ans << endl;
    // system("pause");
}