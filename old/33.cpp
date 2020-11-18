#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int MAXN = 100, MOD = 1e9 + 7;
ll N, K;

struct Mat
{
    ll data[MAXN][MAXN];
    Mat()
    {
        fill(&data[0][0], &data[MAXN - 1][MAXN], 0);
    }
};

Mat matmul(Mat A, Mat B)
{
    Mat out;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                out.data[i][j] = (out.data[i][j] + (A.data[i][k] * B.data[k][j]) % MOD) % MOD;
            }
        }
    }
    return out;
}

Mat fast_pow(Mat base, ll k)
{
    Mat out;
    for (int i = 0; i < N; i++)
    {
        out.data[i][i] = 1;
    }

    while (k > 0)
    {
        if (k & 1)
        {
            out = matmul(base, out);
        }
        base = matmul(base, base);
        k >>= 1;
    }
    return out;
}

int main()
{
    cin >> N >> K;
    Mat a;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a.data[i][j];
        }
    }
    Mat ans = fast_pow(a, K);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans.data[i][j] << " ";
        }
        cout << endl;
    }
    // system("pause");
}