#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int solve(string a, string b, string c)
{
    vector<int> v = prefix_function(b + "#" + a);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == b.length())
        {
            if ()
            a.append(b.substr)
        }
    }
    
}

int main()
{
    string a, b, c;

    int solve(a, b, c);
}
