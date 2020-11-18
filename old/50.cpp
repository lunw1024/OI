#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int mat[1000][1000];

int solve()
{
    int out = 0;
    for (int i = 0; i < N; i++)
    {
        int one = 0, two = 0;
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == -1)
            {
                one = 0, two = 0;
            }
            else
            {
                two = max(two, mat[i][j]);
                if (one < two)
                {
                    swap(one, two);
                }
            }
            out = max(out, one + two);
        }
    }
    return out;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mat[i][j];
        }
    }

    int ans = solve();

    // transpose
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i > j)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }

    ans = max(ans, solve());
    cout << ans << endl;
    // system("pause");
}