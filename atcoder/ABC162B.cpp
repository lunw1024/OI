#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int N;

int main()
{
    cin >> N;
    ll sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 != 0 && i % 5 != 0)
        {
            sum += i;
        }
    }
    cout << sum << endl;
    // system("pause");
}