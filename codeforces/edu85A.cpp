#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, preva, prevb;
        bool flag = true;
        cin >> N >> preva >> prevb;
        if (preva < prevb)
            flag = false;
        for (int j = 1; j < N; j++)
        {
            int a, b;
            cin >> a >> b;
            int da = a - preva, db = b - prevb;
            if (da < 0 || db < 0 || da < db)
                flag = false;
            preva = a, prevb = b;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    // system("pause");
}