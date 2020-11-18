#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

int R, C ,K;
int V[301][301] = {0};
int maxlen[301][301] = {0};

void preprocess()
{
    for (int i = 1; i <= R; i++)
    {
        deque<pair<int, int> > minimum, maximum;
        int head = 1;
        for (int j = 1; j <= C; j++)
        {
            while (!minimum.empty() && V[i][j] - minimum.front().second > K || !maximum.empty() && maximum.front().second - V[i][j] > K)
            {
                maxlen[i][head] = j - head;
                head++;
                if (!minimum.empty() && minimum.front().first < head)
                {
                    minimum.pop_front();
                }
                if (!maximum.empty() && maximum.front().first < head)
                {
                    maximum.pop_front();
                }
            }
            
            while (!minimum.empty() && minimum.back().second >= V[i][j])
            {
                minimum.pop_back();
            }
            minimum.push_back(make_pair(j, V[i][j]));
            while (!maximum.empty() && maximum.back().second <= V[i][j])
            {
                maximum.pop_back();
            }
            maximum.push_back(make_pair(j, V[i][j]));
        }
        // pop the rest
        while (head <= C)
        {
            maxlen[i][head] = C - head + 1;
            head++;
        }
    }
}

int solve(int col)
{
    int out = 0;
    int llim[301] = {0}, rlim[301] = {0};
    stack<pair<int, int> > stk;
    for (int i = 1; i <= R; i++)
    {
        while (!stk.empty() && stk.top().second >= maxlen[i][col])
        {
            stk.pop();
        }
        llim[i] = (stk.empty() ? i : i - stk.top().first);
        stk.push(make_pair(i, maxlen[i][col]));
    }
    while (!stk.empty())
    {
        stk.pop();
    }
    for (int i = 1; i <= R; i++)
    {
        while (!stk.empty() && stk.top().second >= maxlen[R - i + 1][col])
        {
            stk.pop();
        }
        rlim[R - i + 1] = (stk.empty() ? i : i - stk.top().first);
        stk.push(make_pair(i, maxlen[R - i + 1][col]));
    }

    for (int i = 1; i <= R; i++)
    {
        out = max(out, (llim[i] + rlim[i] - 1) * maxlen[i][col]);
    }
    // cout << "col = " << col << "out = " << out << endl;
    return out;
}

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        cin >> R >> C >> K;
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                cin >> V[i][j];
            }
        }
        preprocess();
        // DEBUG
        // for (int i = 1; i <= R; i++)
        // {
        //     for (int j = 1; j <= C; j++)
        //     {
        //         cout << maxlen[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // DEBUG

        int ans = 0;
        for (int i = 1; i <= C; i++)
        {
            ans = max(ans, solve(i));
        }
        cout << "Case #" << caseNo << ": " << ans << endl;
    }
    // system("pause");
}