#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    if (K > (N - 1) * (N - 2) / 2)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << N - 1 + (N - 1) * (N - 2) / 2 - K << endl;
        for (int i = 2; i <= N; i++)
        {
            cout << 1 << " " << i << endl;
        }

        int counter = (N - 1) * (N - 2) / 2 - K;
        for (int i = 2; counter > 0 && i <= N; i++)
        {
            for (int j = i + 1; counter > 0 && j <= N; j++)
            {
                cout << i << " " << j << endl;
                counter--;
            }
        }
        
        
    }
    // system("pause");
}