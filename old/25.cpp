#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

int N;
string s[30000];
bool edges[26][26] = {0};
int indegree[26] = {0};


struct Trie
{
    int data[300000][26], size;
    bool isWord[300000];

    Trie()
    {
        fill(&data[0][0], &data[299999][26], 0);
        fill(isWord, isWord + 300000, false);
        size = 1;
    }

    void insert(string s)
    {
        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (data[p][s[i] - 'a'] == 0)
            {
                data[p][s[i] - 'a'] = size++;
            }
            p = data[p][s[i] - 'a'];
        }
        isWord[p] = true;
    }

    bool find(string s)
    {
        // cout << "in " << s << endl;
        // init
        fill(&edges[0][0], &edges[25][26], false);
        fill(indegree, indegree + 26, 0);

        int p = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isWord[p])
            {
                return false;
            }
            int now = s[i] - 'a';
            for (int j = 0; j < 26; j++)
            {
                if (j != now && data[p][j] > 0 && edges[now][j] == false)
                {
                    edges[now][j] = true;
                    indegree[j]++;
                }
            }
            p = data[p][now];
        }
        
        // topological sort
        queue<int> que;
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }
        while (!que.empty())
        {
            int top = que.front();
            que.pop();
            for (int i = 0; i < 26; i++)
            {
                if (edges[top][i])
                {
                    indegree[i]--;
                    if (indegree[i] == 0)
                    {
                        que.push(i);
                    }
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            // cout << "indegree[" << i << "] = " << indegree[i] << endl;
            if (indegree[i] > 0)
            {
                return false;
            }
        }
        return true;
    }
};

Trie tree;
string arr[30000];
vector<string> out;
int ans = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        tree.insert(arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (tree.find(arr[i]))
        {
            ans++;
            out.push_back(arr[i]);
        }
    }

    // output
    cout << ans << endl;
    for (vector<string>::iterator it = out.begin(); it != out.end(); it++)
    {
        cout << *it << endl;
    }
    // system("pause");
}