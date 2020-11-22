#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int T, N;
int p[200001], c[200001];
bool vis[200001];

int main()
{
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        cin >> N;
        fill(p + 1, p + 1 + N, 0);
        fill(c + 1, c + 1 + N, 0);
        fill(vis + 1, vis + 1 + N, false);

        int ans = 2e5 + 1;
        for (int i = 1; i <= N; i++)
        {
            cin >> p[i];
        }
        for (int i = 1; i <= N; i++)
        {
            cin >> c[p[i]];
        }
        

        for (int i = 1; i <= N; i++)
        {
            vector<int> v;
            if (!vis[i])
            {
                vis[i] = true;
                v.push_back(i);
                int x = i;
                // cout << x << " ";
                while (!vis[p[x]])
                {
                    vis[p[x]] = true;
                    x = p[x];
                    v.push_back(x);
                    // cout << x << " ";
                }
                // cout << endl;

                for (int j = 1; j <= v.size(); j++)
                {
                    if (v.size() % j == 0)
                    {
                        bool flag = true;
                        for (int k = 0; k < v.size(); k += j)
                        {
                            if (c[v[k]] != c[i])
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            ans = min(ans, j);
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < v.size(); j++)
            {
                vis[v[j]] = false;
            }
                      
        }
        cout << ans << endl;
    }
    // system("pause");
}