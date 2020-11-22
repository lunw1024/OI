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
    cout << ((N % 10 == 7 || N / 10 % 10 == 7 || N / 100 == 7) ? "Yes" : "No") << endl;
    // system("pause");
}