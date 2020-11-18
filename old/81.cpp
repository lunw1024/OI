#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 500001;
int N, Q;
int BIT[26][MAXN] = {0};

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int id, int x, int k)
{
    while (x <= N)
    {
        BIT[id][x] = BIT[id][x] + k;
        x = x + lowbit(x);
    }
}

int get_sum(int id, int x)
{
    int ans = 0;
    while (x >= 1)
    {
        ans = ans + BIT[id][x];
        x = x - lowbit(x);
    }
    return ans;
}

int main()
{
    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++)
    {
        add(s[i] - 'a', i + 1, 1);
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx;
            char c;
            cin >> idx >> c;
            add(s[idx - 1] - 'a', idx, -1);
            add(c - 'a', idx, 1);
            s[idx - 1] = c;
        }
        else
        {
            int l, r, cnt = 0;
            cin >> l >> r;
            for (int c = 0; c < 26; c++)
            {
                if (get_sum(c, r) - get_sum(c, l - 1) > 0)
                    cnt++;
            }
            cout << cnt << endl;
        }
        
    }
    // system("pause");
}