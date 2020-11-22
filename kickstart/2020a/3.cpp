#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N, K;
int a[100001];

bool check(int k)
{
    int cost = 0;
    for (int i = 1; i < N; i++)
    {
        cost += (a[i] - a[i - 1] - 1) / k;
    }
    return cost <= K;
}

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        cin >> N >> K;

        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        
        int l = 1, r = a[N - 1];
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            
        }
        cout << "Case #" << caseNo << ": " << l << endl; 
    }
    // system("pause");
}