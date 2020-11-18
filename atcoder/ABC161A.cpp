#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

int N, K;
int a[100] = {0};

int main()
{
    cin >> K;
    int top = 0;
    for (int i = 0; i < K; i++)
    {
        int p = 0;
        while (p < top && (a[p] == a[p + 1] + 1 || a[p] == 9))
        {
            p++;
        }

        if (p == top)
        {
            if (a[p] == 9)
                top++, p++;
        }

        a[p]++;
        for (int j = p - 1; j >= 0; j--)
        {
            a[j] = max(a[j + 1] - 1, 0);
        }
    }

    for (int i = top; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
    // system("pause");
}