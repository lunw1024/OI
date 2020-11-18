#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cassert>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int H, W, K;
bool s[10][1000];

int check(vector<int>& sep)
{
    int out = sep.size() - 2;
    int sum[10] = {0};
    for (int i = 0; i < W; i++)
    {
        int cnt[10] = {0};
        for (int j = 0; j < sep.size() - 1; j++)
        {
            for (int k = sep[j]; k < sep[j + 1]; k++)
            {
                cnt[j] += s[k][i];
            }
        }
        
        bool cut = false;
        for (int j = 0; j < sep.size() - 1; j++)
        {
            sum[j] += cnt[j];
            if (cnt[j] > K)
                return INF;
            else if (sum[j] > K)
            {
                cut = true;
            }
        }

        if (cut)
        {
            for (int j = 0; j < sep.size() - 1; j++)
                sum[j] = cnt[j];
            out++;
        }
    }
    return out;
}

int main()
{
    int ans = INF;
    cin >> H >> W >> K;
    cin.get();
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            s[i][j] = cin.get() == '1';
        }
        cin.get();
    }

    for (int i = 0; i < (1 << H - 1); i++)
    {
        vector<int> sep;
        sep.push_back(0);
        for (int j = 0; j < H - 1; j++)
        {
            if (i & (1 << j))
            {
                sep.push_back(j + 1);
            }
        }
        sep.push_back(H);
        ans = min(ans, check(sep));
    }
    cout << ans << endl;
    // system("pause");
}