#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

bool vis[100001];

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        int N, a = -1, b = -1;
        cin >> N;
        bool flag = true;
        fill(vis + 1, vis + N + 1, false);
        for (int i = 1; i <= N; i++)
        {
            int K;
            cin >> K;
            bool flag1 = true;
            for (int j = 0; j < K; j++)
            {
                int temp;
                cin >> temp;
                if (flag1 && !vis[temp])
                {
                    vis[temp] = true;
                    flag1 = false;
                }                
            }
            if (flag && flag1)
            {
                flag = false;
                a = i;
            }
        }
        if (flag)
        {
            cout << "OPTIMAL" << endl;
        }
        else
        {
            cout << "IMPROVE" << endl;
            for (int i = 1; i <= N; i++)
            {
                if (!vis[i])
                    b = i;
            }
            cout << a << " " << b << endl;
        }
        
        
    }
    // system("pause");
    
}