#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        int x, n, m;
        cin >> x >> n >> m;
        for (int i = 1; x >= 21 && i <= n; i++)
            x = x / 2 + 10;
        for (int i = 1; i <= m; i++)
            x -= 10;
        cout << (x <= 0 ? "YES" : "NO") << endl;
    }
    // system("pause");
}