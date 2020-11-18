#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int N;
ll ans = 0;
pair<int, int> P[(int)1e5 + 1];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i].first;
        P[i].second = i;
    }

    sort(P + 1, P + 1 + N, greater<pair<int, int>>());

    set<int> st;
    for (int i = 1; i <= N; i++)
    {
        int a = 0, b = 0, c = N + 1, d = N + 1;
        set<int>::iterator it = st.lower_bound(P[i].second);
        // cout << P[i].first << " " << P[i].second << endl;
        if (it != st.begin())
        {
            b = *(--it);
            if (it != st.begin())
                a = *(--it);
        }

        it = st.lower_bound(P[i].second);
        if (it != st.end())
        {
            c = *(it++);
            if (it != st.end())
                d = *(it++);
        }

        // cout << a << " " << b << " " << c << " " << d << endl;
        ans += (1ll * (b - a) * (c - P[i].second) + 1ll * (d - c) * (P[i].second - b)) * P[i].first;

        st.insert(P[i].second);
    }
    cout << ans << endl;
    // system("pause");

}