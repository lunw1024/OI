#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 10;
int N;
int arr[MAXN][3][MAXN];

int check(int cl, int a, int b)
{
    int maximum = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = arr[cl][0][i] + arr[cl][1][(i + a) % N] + arr[cl][2][(i + b) % N];
        maximum = max(maximum, sum);
    }
    return maximum;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    // solve
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int minimum = 999999;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                minimum = min(minimum, check(i, j, k));
            }
        }
        ans += minimum;
    }
    cout << ans << endl;
    // system("pause");
}