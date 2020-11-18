#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 100000;
int N;
pair<int, int> edges[MAXN];
pair<int, int> points[MAXN];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    for (int i = 1; i <= N; i++)
    {
        edges[i - 1] = make_pair(points[i - 1].first - points[i % N].first, points[i - 1].second - points[i % N].second);
    }
    bool flag = true;
    if (N % 2 == 0)
    {
        for (int i = 0; i < N / 2; i++)
        {
            if (edges[i].first != -edges[i + N / 2].first || edges[i].second != -edges[i + N / 2].second)
            {
                flag = false;
            }
        }   
    }
    else
    {
        flag = false;
    }
    cout << (flag ? "YES" : "NO") << endl;
    // system("pause");
    
}