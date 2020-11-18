#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 500010;

struct ACautomaton
{
    int tr[MAXN][26] = {{0}}, size = 0;
    int exist[MAXN] = {0}, fail[MAXN];
    queue<int> que;

    void insert(string &s)
    {
        int p = 0;
        for (char ch : s)
        {
            if (tr[p][ch - 'a'] == 0)
                tr[p][ch - 'a'] = ++size;
            p = tr[p][ch - 'a'];
        }
        exist[p]++;
    }

    void build()
    {
        for (int i = 0; i < 26; i++)
            if (tr[0][i] > 0)
                que.push(tr[0][i]);
        while (!que.empty())
        {
            int p = que.front();
            que.pop();
            for (int i = 0; i < 26; i++)
            {
                if (tr[p][i] > 0)
                    fail[tr[p][i]] = tr[fail[p]][i], que.push(tr[p][i]);
                else
                    tr[p][i] = tr[fail[p]][i];
            }
        }
    }

    int query(string &s)
    {
        int p = 0, out = 0;
        for (char ch : s)
        {
            p = tr[p][ch - 'a'];
            for (int i = p; i > 0 && exist[i] != -1; i = fail[i])
                out += exist[i], exist[i] = -1;
        }
        return out;
    }
};

int N;
string words[MAXN];
ACautomaton ac;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
        ac.insert(words[i]);
    }
    ac.build();

    string text;
    cin >> text;
    int ans = ac.query(text);
    cout << ans << endl;
    system("pause");
}