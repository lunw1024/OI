#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
int x[4], y[4];

inline int dist(int a, int b)
{
    return max(min(N - abs(x[a] - x[b]), abs(x[a] - x[b])), min(M - abs(y[a] - y[b]), abs(y[a] - y[b])));
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < 4; i++)
    {
        cin >> x[i] >> y[i];
    }

    int ans = 9999;

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            int k, l;
            for (int ii = 0; ii < 4; ii++)
            {
                if (ii != i && ii != j)
                {
                    k = ii;
                    swap(k, l);
                }
            }
            ans = min(ans, max(dist(i, j), dist(k, l)));
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (i != k && j != k && i != j)
                {
                    ans = min(ans, dist(i, j) + dist(j, k));
                }
            }
        }
    }
    cout << ans << endl;
    // system("pause");
}