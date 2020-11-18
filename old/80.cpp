#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MOD = (int)1e9 + 7;
int N;
bool a[200001];
int pow2[200001];
int ans = 0;
ifstream fin("help.in");
ofstream fout("help.out");

int main()
{
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int l, r;
        fin >> l >> r;
        a[l] = false;
        a[r] = true;
    }

    pow2[0] = 1;
    for (int i = 1; i <= 2 * N; i++)
    {
        pow2[i] = 2 * pow2[i - 1] % MOD;
    }

    int lcnt = 0, rcnt = 0;
    for (int i = 1; i <= 2 * N; i++)
    {
        if (a[i] == true)
        {
            ans = (ans + pow2[rcnt + (N - lcnt)]) % MOD;
        }

        if (a[i] == false)
            lcnt++;
        else
            rcnt++;
        
    }
    fout << ans << endl;
}