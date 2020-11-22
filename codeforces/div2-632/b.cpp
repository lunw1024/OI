#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int a[100000], b[100000];
bool sub[100000], add[100000];

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 0; caseNo < T; caseNo++)
    {
        int N;
        cin >> N;
        bool sub_ = false, add_ = false;
        for (int i = 0; i < N; i++)
        {
            sub[i] = sub_;
            add[i] = add_;
            cin >> a[i];
            if (a[i] == -1)
                sub_ = true;
            if (a[i] == 1)
                add_ = true;
        }
        bool ans = true;
        for (int i = 0; i < N; i++)
        {
            cin >> b[i];
            if (a[i] < b[i] && !add[i])
                ans = false;
            if (a[i] > b[i] && !sub[i])
                ans = false;
        }
        
        cout << (ans ? "YES" : "NO") << endl;
        
    }
    // system("pause");
}