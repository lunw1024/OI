#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int MAXN = 3001;
int N, K, ans = 0;
vector<int> a, b;

int merge(vector<int> &a, int begin, int mid, int end)
{
    int nCount = 0; //前后两段之间逆序的个数
    vector<int> b;

    int j = begin, k = mid + 1;
    int n = end - begin + 1;
    int i = 0;
    for (i = 0; i < n; ++i)
    {
        if (j > mid || k > end)
        {
            break;
        }

        if (a.at(j) <= a.at(k))
        {
            b.push_back(a.at(j));
            ++j;
        }
        else
        {
            b.push_back(a.at(k));
            nCount += mid - j + 1;
            ++k;
        }
    }

    while (j <= mid)
    {
        b.push_back(a.at(j));
        ++j;
    }

    while (k <= end)
    {
        b.push_back(a.at(k));
        ++k;
    }

    for (i = 0; i < n; ++i)
    {
        a[begin + i] = b[i];
    }

    return nCount;
}

int countReversed(vector<int> &a, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        return (countReversed(a, begin, mid) +
                countReversed(a, mid + 1, end) + merge(a, begin, mid, end));
    }
    else
    {
        return 0;
    }
}

int main()
{
    cin >> N >> K;
    cin.get();
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        a.push_back(ch == 'R');
        b.push_back(ch == 'R');
    }

    int k = countReversed(b, 0, N - 1);

    if (k < K)
    {
        cout << -1 << endl;
        // system("pause");
        return 0;
    }

    // cout << "k = " << k << endl;

    for (int i = K; i > 0; i--)
    {
        vector<int> seq;
        for (int j = 0; j < N - 1; j++)
        {
            if (k >= i && a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                seq.push_back(j);
                k--;
            }
        }
        cout << seq.size() << " ";
        for (int j : seq)
            cout << j + 1 << " ";
        cout << endl;
    }

    // system("pause");
}