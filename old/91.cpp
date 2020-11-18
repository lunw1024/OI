#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

struct Edge
{
    int a, b;
    double w;
    Edge(int a = 0, int b = 0, double w = 0)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

bool comp(Edge a, Edge b)
{
    return a.w < b.w;
}

int N;
int fa[1000], maximum[1000] = {0};
int x[1000], y[1000], w[1000], cnt = 0, anscnt = 0;
pair<int, double> ans[1000];
double mst = 0;
Edge edges[1000000];

int find(int p)
{
    return fa[p] == p ? p : fa[p] = find(fa[p]);
}

void merge(int a, int b)
{
    int roota = find(a), rootb = find(b);
    maximum[rootb] = max(maximum[rootb], maximum[roota]);
    fa[roota] = rootb;
}


int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i] >> w[i];
        fa[i] = i;
        maximum[i] = w[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            edges[cnt++] = Edge(i, j, sqrt(1.0 * (pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))));
            // cout << edges[cnt - 1].w << endl;
        }
    }
    
    sort(edges, edges + cnt, comp);

    for (int i = 0; i < cnt; i++)
    {
        int roota = find(edges[i].a), rootb = find(edges[i].b);
        if (roota == rootb)
            continue;

        ans[i] = make_pair(maximum[roota] + maximum[rootb], -edges[i].w);
        mst += edges[i].w;
        anscnt++;
        merge(roota, rootb);
    }

    double maxans = 0;
    for (int i = 0; i < anscnt; i++)
    {
        maxans = max(maxans, (double)ans[i].first / (mst + ans[i].second));
        // cout << ans[i].first << " " << ans[i].second << endl;
    }
    cout << fixed << setprecision(2) << maxans << endl;
    // system("pause");
}