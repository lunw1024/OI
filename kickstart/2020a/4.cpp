#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 2e6 + 1;
int N, K;
int next_[MAXN][26], size = 0;
int cnt[MAXN] = {0};

void add(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'A';
        if (next_[p][c] == 0)
        {
            next_[p][c] = ++size;
        }
        p = next_[p][c];
    }
    cnt[p]++;
}

pair<int, int> add(pair<int, int> a, pair<int, int> b)
{
    return make_pair(a.first + b.first, a.second + b.second);
}

pair<int, int> dfs(int p, int depth)
{

    pair<int, int> out = make_pair(0, cnt[p]);
    for (int i = 0; i < 26; i++)
    {
        if (next_[p][i] > 0)
        {
            // cout << (char)('A' + i) << endl;
            out = add(out, dfs(next_[p][i], depth + 1));
        }
    }
    // cout << "+=" << depth * (out.second / K) << endl;
    out.first += depth * (out.second / K);
    out.second %= K;
    return out;
}

void reset()
{
    fill(&next_[0][0], &next_[size][26], 0);
    fill(cnt, cnt + size + 1, 0);
    size = 0;
}

int main()
{
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        cin >> N >> K;

        reset();

        for (int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            add(s);
        }

        cout << "Case #" << caseNo << ": " << dfs(0, 0).first << endl;
        
    }
    // system("pause");
}