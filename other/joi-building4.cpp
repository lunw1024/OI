#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 1e6 + 1;
int N;
int a[MAXN][2];
int l[MAXN][2] = {0}, r[MAXN][2] = {0};

void backward(int i, int j, int t)
{
    if (i > 0)
    {
        if (a[i - 1][0] <= a[i][j] && l[i - 1][0] <= t - j  && t - j <= r[i - 1][0])
            backward(i - 1, 0, t - j);
        else if (a[i - 1][1] <= a[i][j] && l[i - 1][1] <= t - j  && t - j <= r[i - 1][1])
            backward(i - 1, 1, t - j);
        else
            cout << "error" << endl;
    }
    cout << (j ? "B" : "A");
}

int main()
{
    cin >> N;
    fill(&l[0][0], &l[2 * N - 1][2], 1e9);
    fill(&r[0][0], &r[2 * N - 1][2], -1);

    for (int i = 0; i < 2 * N; i++)
        cin >> a[i][0];
    for (int i = 0; i < 2 * N; i++)
        cin >> a[i][1];

    // init
    l[0][0] = 0, r[0][0] = 0;
    l[0][1] = 1, r[0][1] = 1;

    for (int i = 1; i < 2 * N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (a[i - 1][j] <= a[i][k])
                {
                    l[i][k] = min(l[i][k], l[i - 1][j] + k);
                    r[i][k] = max(r[i][k], r[i - 1][j] + k);
                }
            }
        }
    }
    
    bool flag = false;
    for (int i = 0; i < 2; i++)
    {
        if (l[2 * N - 1][i] <= N && N <= r[2 * N - 1][i])
        {
            backward(2 * N - 1, i, N);
            cout << endl;
            flag = true;
            break;
        }

    }
    if (!flag)
        cout << -1 << endl;
    
    // system("pause");
}