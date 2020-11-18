#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N, M;
int next_[30 * 100001][2] = {0}, cnt = 0;
bool exist[30 * 100001] = {0};
int a[100002], pre[100002], suf[100002], b[100002];

void insert(int x)
{
    int p = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (next_[p][(x & (1 << i)) > 0] == 0)
        {
            next_[p][(x & (1 << i)) > 0] = ++cnt;
        }
        p = next_[p][(x & (1 << i)) > 0];
    }
    exist[p] = true;
}

inline int le(int x)
{
    return (x << 1) | (x >> N - 1);
}

void preprocess()
{
    pre[0] = 0, suf[M + 1] = 0;
    for (int i = 1; i <= M; i++)
    {
        pre[i] = pre[i - 1] ^ le(a[i]);
    }
    for (int i = M; i >= 1; i--)
    {
        suf[i] = suf[i + 1] ^ a[i];
    }
    for (int i = 0; i <= M; i++)
    {
        b[i] = pre[i] ^ suf[i + 1];
    }
}

int ans1 = 0, ans2 = 0;
void solve(int p, int depth, int value)
{
    // cout << p << " " << depth << " " << value << " " << next_[p][0] << " " << next_[p][1] << endl;
    if (next_[p][0] > 0 && next_[p][1] > 0)
    {
        solve(next_[p][0], depth + 1, value);
        solve(next_[p][1], depth + 1, value);
    }
    else if (next_[p][0] > 0)
    {
        solve(next_[p][0], depth + 1, value + (1 << (N - 1 - depth)));
    }
    else if (next_[p][1] > 0)
    {
        solve(next_[p][1], depth + 1, value + (1 << (N - 1 - depth)));
    }
    else
    {
        if (depth != N)
            cout << "error, p=" << p << endl;
        if (ans1 < value)
        {
            ans1 = value;
            ans2 = 1;
        }
        else if (ans1 == value)
        {
            ans2++;
        }
    }
    
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> a[i];
    }

    preprocess();

    for (int i = 0; i <= M; i++)
    {
        insert(b[i]);
    }
    
    solve(0, 0, 0);
    
    cout << ans1 << endl << ans2 << endl;    
    // system("pause");
}