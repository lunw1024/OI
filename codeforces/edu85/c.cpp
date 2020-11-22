#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int N;
ll a[300000], b[300000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> a[i] >> b[i];
        }
        ll sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += max(0ll, a[i] - b[(i - 1 + N) % N]);
        }
        ll ans = 4e18;
        for (int i = 0; i < N; i++)
        {
            ans = min(ans, sum - max(0ll, a[i] - b[(i - 1 + N) % N]) + a[i]);
        }
        cout << ans << endl;
        

    }
    // system("pause");
}