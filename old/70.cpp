#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 100001;
int N, BIT[MAXN], ans = 1;
pair<int, int> arr[MAXN];
ifstream fin("sort.in");
ofstream fout("sort.out");

int lowbit(int x)
{
    return x & -x;
}

void add(int idx, int k)
{
    while (idx <= N)
    {
        BIT[idx] += k;
        idx += lowbit(idx);
    }
}

int prefix(int idx)
{
    int out = 0;
    while (idx > 0)
    {
        out += BIT[idx];
        idx -= lowbit(idx);
    }
    return out;
}

int main()
{
    fin >> N;
    for (int i = 1; i <= N; i++)
    {
        fin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + 1 + N);
    for (int i = 1; i <= N; i++)
    {
        add(arr[i].second, 1);
        ans = max(ans, i - prefix(i));
    }
    fout << ans << endl;
    // system("pause");
}