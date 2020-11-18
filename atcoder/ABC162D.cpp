#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int N;
string s;
ll ans = 0;

int main()
{
    cin >> N >> s;
    ll a = 0, b = 0, c = 0, ab = 0, bc = 0, ac = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'R')
        {
            a += 1;
            ab += b;
            ac += c;
            ans += bc;
        }
        else if (s[i] == 'G')
        {
            b += 1;
            ab += a;
            bc += c;
            ans += ac;
        }
        else if (s[i] == 'B')
        {
            c += 1;
            ac += a;
            bc += b;
            ans += ab;
        }
    }
    // cout << ans << endl;

    for (int i = 0; i < N; i++)
    {
        for (int k = 1; i + 2 * k < N; k++)
        {
            if (s[i] != s[i + k] && s[i] != s[i + 2 * k] && s[i + k] != s[i + 2 * k])
            {
                // cout << i << " " << i + k << " " << i + 2 * k << endl;
                ans--;
            }
        }
    }
    cout << ans << endl;
    // system("pause");
}