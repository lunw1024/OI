#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

int T, R, C;
int dist[251][251] = {0};
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


bool check(int k)
{
    // filter & calculate the bounding box
    int SE = -1e9, SW = -1e9, NW = 1e9, NE = 1e9;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (dist[i][j] > k)
            {
                SE = max(SE, i + j);
                SW = max(SW, i - j);
                NW = min(NW, i + j);
                NE = min(NE, i - j);
            }
        }
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (SE - (i + j) <= k && SW - (i - j) <= k && (i + j) - NW <= k && (i - j) - NE <= k)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        cin >> R >> C;
        fill(&dist[0][0], &dist[250][251], (int)1e9);
        queue<pair<int, int> > que;
        for (int i = 1; i <= R; i++)
        {
            cin.get();
            for (int j = 1; j <= C; j++)
            {
                if (cin.get() == '1')
                {
                    que.push(make_pair(i, j));
                    dist[i][j] = 0;
                }
            }
        }

        // BFS
        while (!que.empty())
        {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] <= 0 || x + dx[i] > R || y + dy[i] <= 0 || y + dy[i] > C)
                {
                    continue;
                }
                if (dist[x + dx[i]][y + dy[i]] > dist[x][y] + 1)
                {
                    dist[x + dx[i]][y + dy[i]] = dist[x][y] + 1;
                    que.push(make_pair(x + dx[i], y + dy[i]));
                }
            }
        }

        // binary search
        int l = 0, r = (R + C) / 2;
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