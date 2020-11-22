#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

int N;
string s, t;
int pos[26][100000], head[26] = {0};

int main()
{
    cin >> s >> t;
    N = s.size();
    fill(&pos[0][0], &pos[25][100000], -1);

    // preprocess
    for (int i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        while (head[c] <= i)
        {
            pos[c][head[c]++] = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        while (head[i] < N)
        {
            pos[i][head[i]++] = pos[i][0];
        }
    }

    ll ans = -1;
    for (char ch : t)
    {
        int c = ch - 'a';
        if (pos[c][(ans + 1) % N] == -1)
        {
            ans = -1;
            break;
        }
        if (pos[c][(ans + 1) % N] <= ans % N)
        {
            ans = (ans / N + 1) * N + pos[c][(ans + 1) % N];
            // cout << ans << endl;
        }
        else
        {
            ans = ans / N * N + pos[c][(ans + 1) % N];
            // cout << ans << endl;
        }
    }
    cout << (ans == -1 ? -1 : ans + 1) << endl;

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << (char)(i + 'a') << ": ";
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << pos[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // system("pause");

}