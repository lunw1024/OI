#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

bool canUnderstand[1000001] = {0};
int ans = 0;

struct Trie
{
    int next_[200][26], size;
    bool exist[200];
    
    Trie()
    {
        fill(&next_[0][0], &next_[199][26], 0);
        fill(exist, exist + 200, false);
        size = 1;
    }

    void insert(string s)
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
        exist[p] = true;
    }

    inline void find(string& s, int head)
    {
        int p = 0;
        for (int i = head; i < s.size(); i++)
        {
            if (next_[p][s[i] - 'a'] == 0)
            {
                return;
            }            
            p = next_[p][s[i] - 'a'];
            if (exist[p])
            {
                canUnderstand[i + 1] = true;
                ans = max(ans, i + 1);
            }
        }
    }
};

int N, M;
Trie trie;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        trie.insert(s);
    }

    for (int i = 0; i < M; i++)
    {
        string passage;
        cin >> passage;
        memset(canUnderstand, 0, sizeof(canUnderstand) + sizeof(bool));
        // fill(canUnderstand, canUnderstand + passage.size() + 1, false);
        ans = 0;
        canUnderstand[0] = true;
        for (int j = 0; j < passage.size(); j++)
        {
            if (!canUnderstand[j])
            {
                continue;
            }
            
            trie.find(passage, j);
        }
        
        cout << ans << endl;
    }
    // system("pause");
}