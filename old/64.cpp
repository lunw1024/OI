#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int arr[100000];

int main()
{
    int N, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int k = 30; k >= 0; k--)
    {
        int cnt = 0, base = 1 << k;
        for (int i = 0; i < N && cnt < 2; i++)
        {
            if (arr[i] & base)
            {
                cnt++;
                ans = i;
            }
        }
        if (cnt == 1)
        {
            break;
        }
    }

    cout << arr[ans] << " ";
    for (int i = 0; i < N; i++)
    {
        if (i == ans)
            continue;
        cout << arr[i] << " ";
    }
    cout << endl;
    // system("pause");
}