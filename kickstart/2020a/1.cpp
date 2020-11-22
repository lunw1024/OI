#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        int N, B;
        cin >> N >> B;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (; B - v[ans] >= 0 && ans < N; ans++)
        {
            B -= v[ans];
        }
        cout << "Case #" << caseNo << ": " << ans << endl;
        
        
    }
    // system("pause");
}