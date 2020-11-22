#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 1;
int N;
ll a[MAXN], pre[MAXN] = {0}, ans = 0;
map<ll, int> mp;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        mp[pre[i]] = -1;

    }

    int lim = 0;
    mp[0] = 0; 
    for (int i = 1; i <= N; i++)
    {
        lim = max(lim, mp[pre[i]] + 1);
        // cout << lim << endl;
        ans += i - lim;
        mp[pre[i]] = i;

    }

    cout << ans << endl;
    // system("pause");
}