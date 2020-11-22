#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long n, k;
        cin >> n >> k;
        if (n % 2 != k % 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << (n >= k * k ? "YES" : "NO") << endl; 
        }
        
    }
    // system("pause");
    
}