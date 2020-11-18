#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 100001;
int N, M, K, base[MAXN];
int arr[MAXN], temp[MAXN];
ifstream fin("swap.in");
ofstream fout("swap.out");

void mul(int a[], int b[])
{
    for (int i = 1; i <= N; i++)
    {
        temp[i] = a[b[i]];
    }
    for (int i = 1; i <= N; i++)
    {
        a[i] = temp[i];
    }
}

int main()
{
    fin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        base[i] = i;
        arr[i] = i;
    }
    
    for (int i = 1; i <= M; i++)
    {
        int l, r;
        fin >> l >> r;
        reverse(base + l, base + r + 1);
        // for (int i = 1; i <= N; i++)
        //     cout << base[i] << " ";
        // cout << endl;
    }


    while (K > 0)
    {
        if (K & 1)
        {
            mul(arr, base);
        }
        mul(base, base);
        K >>= 1;
    }

    for (int i = 1; i <= N; i++)
    {
        fout << arr[i] << endl;
    }
    // system("pause");
}