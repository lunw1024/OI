#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
typedef long long ll;

const int MAXN = 5001;
int N, Q;
pair<ll, int> A[MAXN];                // (w, id)
vector<pair<int, ll>> lb[MAXN];       // (lbound, cnt)
vector<pair<int, int>> queries[MAXN]; // (id, l)
ll d[MAXN * 4] = {0}, b[MAXN * 4] = {0};
ll ans[100000] = {0};
ifstream fin("threesum.in");
ofstream fout("threesum.out");

void update(int l, int r, int c, int s, int t, int p)
{
    // [l,r] 为修改区间,c 为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
    // 为当前节点的编号
    if (l <= s && t <= r)
    {
        d[p] += (t - s + 1) * c, b[p] += c;
        return;
    } // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
    int m = (s + t) / 2;
    if (b[p] && s != t)
    {
        // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p], b[p * 2 + 1] += b[p]; // 将标记下传给子节点
        b[p] = 0;                               // 清空当前节点的标记
    }
    if (l <= m)
        update(l, r, c, s, m, p * 2);
    if (r > m)
        update(l, r, c, m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

int getsum(int l, int r, int s, int t, int p)
{
    // [l,r] 为修改区间,c 为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
    // 为当前节点的编号
    if (l <= s && t <= r)
        return d[p];
    // 当前区间为询问区间的子集时直接返回当前区间的和
    int m = (s + t) / 2;
    if (b[p])
    {
        // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m),
            b[p * 2] += b[p], b[p * 2 + 1] += b[p]; // 将标记下传给子节点
        b[p] = 0;                                   // 清空当前节点的标记
    }
    int sum = 0;
    if (l <= m)
        sum = getsum(l, r, s, m, p * 2);
    if (r > m)
        sum += getsum(l, r, m + 1, t, p * 2 + 1);
    return sum;
}

int main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A + 1, A + N + 1);

    for (int i = 1; i <= N; i++)
    {
        ll target = -A[i].first;
        int l = i + 1, r = N;
        ll lcnt = 1;
        int ll = A[l].second, lr = A[l].second;
        while (l < r)
        {
            while (l + 1 <= N && A[l].first == A[l + 1].first)
            {
                l++;
                lcnt++;
            }
            // while (r - 1 >= 1 && A[r].first == A[r - 1].first)
            // {
            //     r--;
            //     rcnt++;
            // }

            if (A[l].first + A[r].first == target)
            {
                int lbound = min(A[i].second, min(A[l].second, A[r].second));
                int rbound = max(A[i].second, max(A[l].second, A[r].second));
                lb[rbound].push_back(make_pair(lbound, lcnt));
                // cout << l << "+" << r << "=" << i << "cnt = " << cnt << endl;
                r--;
                continue;
            }
            if (A[l].first + A[r].first < target)
            {
                lcnt = 1;
                l++;
            }
            else
            {
                r--;
            }
        }
        // special
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries[r].push_back(make_pair(i, l));
    }

    for (int i = 1; i <= N; i++)
    {
        // activate lb
        for (int j = 0; j < lb[i].size(); j++)
        {
            add(lb[i][j].first, lb[i][j].second);
        }

        for (int j = 0; j < queries[i].size(); j++)
        {
            ans[queries[i][j].first] = getsum(i) - getsum(queries[i][j].second - 1);
        }
    }

    for (int i = 0; i < Q; i++)
    {
        cout << ans[i] << endl;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << getsum(i) - getsum(i - 1) << endl;
    }

    system("pause");
}