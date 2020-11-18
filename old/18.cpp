#include <iostream>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;

struct City
{
    int index, height;
    City(int index = 0, int height = 0)
    {
        this->index = index;
        this->height = height;
    }
    bool operator<(const City& o) const
    {
        return this->height < o.height;
    }
};

int N, X, M;
int h[100001], s[100001], x[100001];
int Adis[100001][17] = {0}, Bdis[100001][17] = {0}, st[100001][17] = {0};
int min2[100001] = {0}, min1[100001] = {0}; 

void preprocess()
{
    set<City> set_;
    for (int i = N; i >= 1; i--)
    {
        set_.insert(City(i, h[i]));
        set<City>::iterator it = set_.find(City(i, h[i]));
        City l, r, l2, r2;// not exist set to 0
        int temp = 2;
        if (it != set_.begin())
            l = *(--it);
        else
            temp--;
        if (it != set_.begin())
            l2 = *(--it);
        else
            temp--;
        for (int j = 0; j < temp; j++)
        {
            it++;
        }
        if (it != set_.end())
            r = *(++it);
        if (it != set_.end())
            r2 = *(++it);

        // TODO: min1 should be the least among 4 variables, min2 should be the second least

        if (l.index == 0)
        {
            min1[i] = r.index;
        }
        else if (r.index == 0)
        {
            min1[i] = l.index;
        }
        else
        {
            min1[i] = abs(h[i] - l.height) < abs(h[i] - r.height) ? l.index : r.index;
        }

        if (l2.index == 0)
        {
            min2[i] = r2.index;
        }
        else if (r2.index == 0)
        {
            min2[i] = l2.index;
        }
        else
        {
            min2[i] = abs(h[i] - l2.height) < abs(h[i] - r2.height) ? l2.index : r2.index;
        }
        // if overflow, min[i] set to 0
    }

    for (int i = 1; i <= N; i++)
    {
        if (min1[min2[i]] > 0)// if overflow, dis set to 0
        {
            Adis[i][0] = abs(h[i] - h[min2[i]]);
            Bdis[i][0] = abs(h[min2[i]] - h[min1[min2[i]]]);
        }
        st[i][0] = min1[min2[i]];
    }

    for (int k = 1; k < 17; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            Adis[i][k] = Adis[i][k - 1] + Adis[st[i][k - 1]][k - 1];// if st[i] == 0 then dis[i][k] = dis[i][k - 1]
            Bdis[i][k] = Bdis[i][k - 1] + Bdis[st[i][k - 1]][k - 1];
            st[i][k] = st[st[i][k - 1]][k - 1];// overflow set to 0
        }
    }
}

int query1()
{
    int minimum = 1110000000, index = 0, height = 0;
    for (int start = 1; start <= N; start++)
    {
        // get max pos
        int now = start, a = 0, b = 0, total = 0;
        for (int k = 16; k >= 0; k--)
        {
            if (st[now][k] > 0 && total + Adis[now][k] + Bdis[now][k] <= X)// exist & doesn't exceed X
            {
                a += Adis[now][k];
                b += Bdis[now][k];
                total = a + b;
                now = st[now][k];
            }
        }
        // last step
        if (min2[now] > 0)
        {
            a += abs(h[now] - h[min2[now]]);
            now = min2[now];
        }

        // update
        int temp = (b == 0 ? 1100000000 : a / b);
        cout << "start = " << start << " a = " << a << " b = " << b << endl;
        if (temp == minimum)
        {
            if (h[start] > height)
            {
                index = start;
            }
        }
        else if (minimum > temp)
        {
            minimum = temp;
            index = start;
        }
    }
    return index;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> h[i];
    }
    cin >> X >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> s[i] >> x[i];
    }
    preprocess();
    cout << query1();
    system("pause");
}