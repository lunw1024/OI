#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN = (int)2e5 + 1;
int N;
ll A[MAXN], F[MAXN], K;

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= N; i++)
        cin >> F[i];

    sort(A + 1, A + 1 + N);
    sort(F + 1, F + 1 + N, greater<ll>());

    ll l = 0, r = (ll)1e18;
    while (l <= r)
    {
        ll k = 0;
        ll mid = (l + r) / 2;
        for (int i = 1; i <= N; i++)
            k += max(0ll, A[i] - mid / F[i]);

        if (k > K)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << l << endl;
    // system("pause");
    
}