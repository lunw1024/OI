#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N, maxLen, sticks[51] = {0}, usedNum = 0;
vector<int> factor;

bool dfs(int targetSize, int progress, int prev)
{
    // cout << progress << endl;
    if (usedNum == N && progress == 0)
    {
        return true;
    }

    for (int i = min(min(prev, 50), targetSize - progress); i >= 0; i--)
    {
        if (sticks[i] == 0)
        {
            continue;
        }
        int flag = false;
        // cout << "sticks[" << i << "]--" << endl;
        sticks[i]--;
        if (progress + i == targetSize)
        {
            usedNum++;
            flag = dfs(targetSize, 0, 50);
            usedNum--;
        }
        else
        {
            usedNum++;
            flag = dfs(targetSize, progress + i, i);
            usedNum--;
        }
        // cout << "sticks[" << i << "]++" << endl;
        sticks[i]++;

        if (flag)
        {
            return true;
        }

        if (flag == false && (progress == 0 || progress + i == targetSize))
        {
            return false;
        }
    }
    return false;
}

void factorize(int x)
{
    for (int i = maxLen; i <= x; i++)
    {
        if (x % i == 0)
        {
            factor.push_back(i);
        }
    }
}

int main()
{
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int len;
        cin >> len;

        if (len > 50)
        {
            i--;
            N--;
            continue;
        }
        sticks[len]++;
        sum += len;
        maxLen = max(maxLen, len);
    }

    factorize(sum);
    for (vector<int>::iterator it = factor.begin(); it != factor.end(); it++)
    {
        if (dfs(*it, 0, 50))
        {
            cout << *it << endl;
            break;
        }
    }
    // system("pause");
}