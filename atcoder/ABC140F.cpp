#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int N;
multiset<int, greater<int>> st1, st2;

int main()
{
    cin >> N;
    for (int i = 0; i < (1 << N); i++)
    {
        int a;
        cin >> a;
        st1.insert(a);
    }
    st2.insert(*st1.begin());
    st1.erase(st1.begin());
    for (int i = 1; i <= N; i++)
    {
        vector<int> v;
        for (auto it2 = st2.begin(); it2 != st2.end(); it2++)
        {
            auto it1 = st1.upper_bound(*it2);
            if (it1 != st1.end())
                v.push_back(*it1), st1.erase(it1);
            else
            {
                cout << "No" << endl;
                // system("pause");
                return 0;
            }
        }
        
        for (int ele : v)
            st2.insert(ele);
    }
    cout << "Yes" << endl;
    // system("pause");
}