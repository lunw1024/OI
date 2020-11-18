#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

string s;
int n;

void dfs(int depth, int last)
{
    if (depth == n)
    {
        cout << s << "\n";
        return;
    }

    for (int i = 0; i <= last + 1; i++)
    {
        s[depth] = 'a' + i;
        dfs(depth + 1, max(last, i));
    }
    
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s.append("a");
    }
    
    dfs(0, -1);
    // system("pause");
}