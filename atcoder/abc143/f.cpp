#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)3e5 + 2;
int N;
int cnt[MAXN] = {0}, pre[MAXN] = {0};
int pos[MAXN] = {0};
int f[MAXN] = {0}, ans[MAXN] = {0};

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }

    sort(cnt + 1, cnt + 1 + N);

    for (int i = 1; i <= N; i++)
        pre[i] = pre[i - 1] + cnt[i];

    cnt[N + 1] = (int)1e9;
    for (int i = 1, x = 1; i <= N + 1 && x <= N; i++)
    {
        while (x <= N && cnt[i] >= x)
        {
            pos[x] = i;
            x++;
        }
    }

    for (int x = 1; x <= N; x++)
        f[x] = (pre[pos[x] - 1] + (N - pos[x] + 1) * x) / x;

    for (int i = 1; i <= N; i++)
        ans[f[i]] = max(ans[f[i]], i);

    for (int k = N - 1; k >= 0; k--)
        ans[k] = max(ans[k], ans[k + 1]);

    for (int k = 1; k <= N; k++)
        cout << ans[k] << endl;
}