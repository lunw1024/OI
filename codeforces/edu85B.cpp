#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        ll N, K;
        cin >> N >> K;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end(), greater<int>());

        ll sum = 0, ans = N;
        for (int i = 0; i < N; i++)
        {
            sum += v[i];
            if (sum < K * (i + 1))
            {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    // system("pause");
}