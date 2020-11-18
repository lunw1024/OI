#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int mat[9][9] = {0}, dx[2] = {1, 0}, dy[2] = {0, 1};
int ans = 0;

void check(int x, int y, int dir)
{
    if (mat[x][y] == 0)
    {
        return;
    }
    int num = 0, sum = 0;
    while (x <= N && y <= N)
    {
        num = num * 10 + mat[x][y];
        sum += mat[x][y];
        if (num % sum == 0)
        {
            ans = max(ans, num);
        }
        x += dx[dir], y += dy[dir];
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin.get();
        for (int j = 1; j <= N; j++)
        {
            mat[i][j] = cin.get() - '0';
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int dir = 0; dir <= 1; dir++)
            {
                check(i, j, dir);
            }
        }
    }
    cout << ans << endl;
    // system("pause");
}