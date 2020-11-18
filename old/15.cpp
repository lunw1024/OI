#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N, M;
vector<int> prime;
bool isNotPrime[10000001] = {0};

void euler_sieve()
{
    isNotPrime[0] = true;
    isNotPrime[1] = true;
    for (int i = 2; i <= N; i++)
    {
        if (!isNotPrime[i])
        {
            prime.push_back(i);
        }
        for (vector<int>::iterator it = prime.begin(); it != prime.end() && *it * i <= N; it++)
        {
            isNotPrime[*it * i] = true;
            if (i % *it == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    euler_sieve();
    for (int i = 0; i < M; i++)
    {
        int q;
        cin >> q;
        cout << (isNotPrime[q] ? "No" : "Yes") << endl;
    }
    // system("pause");
}