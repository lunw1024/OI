#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1000002, MAXM = 1000002;
int N, M;
ll a[MAXN] = {0};
vector<pair<int, ll> > rent[MAXN];

bool check(int p)
{
    ll temp = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < rent[i].size(); j++)
        {
            pair<int, ll> ele = rent[i][j];
            if (ele.first > p)
            {
                break;
            }

            temp += ele.second;
        }
        // cout << "temp[" << i << "] = " << temp << "\n";
        if (temp > a[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= M; i++)
    {
        int s, t;
        ll d;
        cin >> d >> s >> t;
        rent[s].push_back(make_pair(i, d));
        rent[t + 1].push_back(make_pair(i, -d));
    }

    int l = 1, r = M;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            // cout << "right in " << mid << "\n";
        }
        else
        {
            r = mid - 1;
        }
    }

    if (l == M + 1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << -1 << "\n"
             << l << "\n";
    }
    // system("pause");
}