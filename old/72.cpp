#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 100000;

int N, M, T;
int parent[MAXN];

int ufs_find(int p)
{
    return parent[p] == p ? p : parent[p] = ufs_find(parent[p]);
}

void ufs_union(int a, int b)
{
    int roota = ufs_find(a), rootb = ufs_find(b);
    parent[rootb] = roota;
}

int main()
{
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        // init
        cin >> N >> M;
        int ans = 0, cnt = 0;
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
        }
        
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (ufs_find(a) != ufs_find(b))
            {
                ufs_union(a, b);
                ans += 1;
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (i == ufs_find(i))
                cnt++;
        }
        
        ans += 2 * (cnt - 1);
        cout << "Case #" << caseNo << ": " << ans << endl;
    }
    // system("pause"); 
}
