#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 200002;
const char JOI[3] = {'J', 'O', 'I'};
int N, K, ans = 999999;
string S;
int prefix[MAXN] = {0}, suffix[MAXN] = {0};// 0 == illigal

int main()
{
    cin >> N >> K >> S;
    
    deque<int> que;
    for (int i = 1; i <= N; i++)
    {
        if (S[i - 1] == 'J')
            que.push_back(i);
        if (que.size() > K)
            que.pop_front();
        if (que.size() == K)
            prefix[i] = que.front();
    }
    que.clear();
    for (int i = N; i >= 1; i--)
    {
        if (S[i - 1] == 'I')
            que.push_back(i);
        if (que.size() > K)
            que.pop_front();
        if (que.size() == K)
            suffix[i] = que.front();
    }

    que.clear();
    for (int i = 1; i <= N; i++)
    {
        if (S[i - 1] == 'O')
            que.push_back(i);
        if (que.size() > K)
            que.pop_front();
        if (que.size() == K && prefix[que.front()] != 0 && suffix[que.back()] != 0)
        {
            ans = min(ans, suffix[que.back()] - prefix[que.front()] + 1 - 3 * K);
        }
    }
    cout << (ans == 999999 ? -1 : ans) << endl;
    // system("pause");
}