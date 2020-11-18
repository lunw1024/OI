#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N, M, K;

int main()
{
    int mx = 0, my = 0;
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        mx = max(mx, x), my = max(my, y);
    }
    cout << mx - 1 + my - 1 + N * M - 1 << endl;
    for (int i = 1; i <= mx - 1; i++)
    {
        cout << "U";
    }
    for (int i = 1; i <= my - 1; i++)
    {
        cout << "L";
    }
    int x = 1, y = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M - 1; j++)
        {
            cout << (i % 2 == 1 ? "R" : "L");
        }
        cout << (i < N ? "D" : "");
    }
    // system("pause");
    
    
}