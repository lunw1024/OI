#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll a, b, k;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> a >> b >> k;
        if (a > b)
            swap(a, b);
        ll c = gcd(a, b);
        if (a == b) {
            cout << ((k >= 2) ? "YES" : "NO") << endl;
        } else if (k <= (b - c - 1) / a + 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    // system("pause");
}
