#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

string a, b;
int next_[1000000] = {0};

void preprocess()
{
    for (int i = 1; i < b.size(); i++)
    {
        int j = next_[i - 1];
        while (j > 0 && b[i] != b[j])
        {
            j = next_[j - 1];
        }
        if (b[i] == b[j])
        {
            j++;
        }
        next_[i] = j;
    }
}

void KMP(string s)
{
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j > 0 && s[i] != b[j])
        {
            j = next_[j - 1];
        }
        if (s[i] == b[j])
        {
            j++;
        }
        if (j == b.size())
        {
            cout << i - j + 2 << endl;
            j = next_[j - 1];
        }
    }
}

int main()
{
    cin >> a >> b;
    preprocess();
    KMP(a);

    for (int i = 0; i < b.size(); i++)
    {
        cout << next_[i] << " ";
    }
    cout << endl;
    // system("pause");
}