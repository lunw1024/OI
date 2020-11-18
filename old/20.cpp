#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N, M;
vector<string> articles[1000];
vector<int> ans[10001];

struct Trie
{
    int next_[200000][26], size;
    vector<int> exist[200000];

    Trie()
    {
        fill(&next_[0][0], &next_[200000 - 1][26], 0);
        size = 1;
    }

    void insert(string s, int index)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (next_[p][s[i] - 'a'] == 0)
            {
                next_[p][s[i] - 'a'] = size++;
            }
            p = next_[p][s[i] - 'a'];
        }
        exist[p].push_back(index);
    }

    vector<int>& find(string s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (next_[p][s[i] - 'a'] == 0)
            {
                vector<int> v;
                return v;
            }
            p = next_[p][s[i] - 'a'];
        }
        return exist[p];
    }
};

Trie tree;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int L;
        cin >> L;
        for (int j = 0; j < L; j++)
        {
            string s;
            cin >> s;
            articles[i].push_back(s);
        }
    }

    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        string s;
        cin >> s;
        tree.insert(s, i);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < articles[i].size(); j++)
        {
            vector<int> v = tree.find(articles[i][j]);
            for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
            {
                if (ans[*it].empty() || ans[*it].back() != i)
                {
                    ans[*it].push_back(i);
                }
            }
        }
    }

    for (int i = 1; i <= M; i++)
    {
        for (vector<int>::iterator it = ans[i].begin(); it != ans[i].end(); it++)
        {
            cout << (*it) + 1 << (ans[i].end() - it == 1 ? "" : " ");
        }
        cout << endl;
    }
    // system("pause");
}