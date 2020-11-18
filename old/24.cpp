#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;

int N, T, Q, M;
 
const ll MOD[2] = {1e9 + 7, 1e9 + 9}, BASE = 1e5 + 1;
ll S[BASE], SHash[2];
vector<ll> a[BASE], aHash[2][BASE];
int sequence[BASE];
int cnt[BASE] = {0};
ll power[2][BASE];// BASE^j % MOD[i]

void preprocess()
{
    // SHash
    for (int i = 0; i < T; i++)
    {
        cnt[S[i]]++;
    }

    for (int hash = 0; hash < 2; hash++)
    {
        ll buffer = 0;
        for (int i = 0; i < BASE; i++)
        {
            buffer = (buffer * BASE + cnt[i]) % MOD[hash];
        }
        SHash[hash] = buffer;
    }

    // preprocess exp
    for (int i = 0; i < 2; i++)
    {
        power[i][0] = 1;
        for (int j = 1; j < BASE; j++)
        {
            power[i][j] = power[i][j - 1] * BASE % MOD[i];
        }
    }

    // aHash
    for (int hash = 0; hash < 2; hash++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                aHash[hash][i][j] = (aHash[hash][i][j - 1] + 
                power[hash][BASE - 1 - a[i][j]]) % MOD[hash];
            }
        }
    }
}

int main()
{
    // read
    cin >> N >> T >> Q;
    for (int i = 0; i < T; i++)
    {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            int x;
            cin >> x;
            a[i].push_back[x];
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> sequence[i];
        sequence[i]--;
    }

    deque<int> que;// window size = T
    // find mink s.t kM >= T
    int k = (T - 1) / M + 1;
    int residual = Q % (k * M);
    assert(Q > k * M);

    // first kM
    // TODO: rolling window


}