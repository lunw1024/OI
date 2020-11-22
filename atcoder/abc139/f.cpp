#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

int N;
pair<int, int> points[100];

bool comp(pair<int, int> a, pair<int, int> b)
{
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

int main()
{
    double ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    sort(points, points + N, comp);

    for (int l = 0; l < N; l++)
    {
        for (int r = l + 1; r <= N; r++)
        {
            pair<int, int> sum[2];
            for (int i = 0; i < N; i++)
            {
                if (l <= i && i < r)
                {
                    sum[0].first += points[i].first;
                    sum[0].second += points[i].second;
                }
                else
                {
                    sum[1].first += points[i].first;
                    sum[1].second += points[i].second;
                }
            }
            ans = max(ans, max(sqrt(pow(sum[0].first, 2) + pow(sum[0].second, 2)), sqrt(pow(sum[1].first, 2) + pow(sum[1].second, 2))));
        }
    }
    
    cout << setiosflags(ios::fixed) << setprecision(12) << ans << endl;
    // system("pause");
}