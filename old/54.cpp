#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;

int main()
{
    cin >> N >> M;
    int l = 999, r = -1;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        l = min(l, a), r = max(r, a);
    }
    int ans = 999;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        ans = min(ans, min(abs(a - l), abs(a - r)) + r - l);
    }
    cout << ans << endl;
    // system("pause");
}