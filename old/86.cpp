#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Trie
{
    int next_[50000 * 50 + 1][26] = {{0}}, size = 0;
    bool exist[50000 * 50 + 1];

    void insert(string& s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (next_[p][c] == 0)
                next_[p][c] = ++size;
            p = next_[p][c];
        }
        exist[p] = true;
    }

    int solve(int p)
    {
        int out = 1;
        for (int i = 0; i < 26; i++)
        {
            if (next_[p][i] != 0)
            {
                int temp = solve(next_[p][i]);
                out = out * (temp + 1) % 9191;
            }
        }
        if (!exist[p])
            out--;
        return out % 9191;
    }
};

Trie t;
int N;

int main()
{
    cin >> N;
    t.exist[0] = true;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        t.insert(s);
    }
    cout << t.solve(0) << endl;
    // system("pause");
}