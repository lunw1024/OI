#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

int N, M, P;

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

int main()
{
    cin >> N >> M >> P;
    int a = 9999999, b = 9999999;
    for (int i = 0; i < N; i++)
    {
        int temp = read();
        if (a == 9999999 && temp % P != 0)
            a = i;
    }

    for (int i = 0; i < M; i++)
    {
        int temp = read();
        if (b == 9999999 && temp % P != 0)
            b = i;
    }

    cout << a + b << endl;
    // system("pause");
}