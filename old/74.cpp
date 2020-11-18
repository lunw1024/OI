#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N, K, l1, r1, l2, r2;
int ans[101];
ifstream fin("swap.in");
ofstream fout("swap.out");

int main()
{
    fin >> N >> K;
    fin >> l1 >> r1 >> l2 >> r2;
    for (int i = 1; i <= N; i++)
    {
        int p = i;
        for (int j = 1; j <= K; j++)
        {
            if (l1 <= p && p <= r1)
                p = l1 + r1 - p;
            if (l2 <= p && p <= r2)
                p = l2 + r2 - p;
            if (p == i) // j is the period
                j = K - K % j;
        }
        ans[p] = i;
    }
    
    for (int i = 1; i <= N; i++)
    {
        fout << ans[i] << endl;
    }
}