#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXS = 100002;
int T, D, S;
int prefix[MAXS], suffix[MAXS];
pair<int, int> V[MAXS];

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first * b.second > b.first * a.second;
}

int main()
{
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++)
    {
        cin >> D >> S;
        fill(prefix, prefix + S + 2, 0);
        fill(suffix, suffix + S + 2, 0);

        for (int i = 1; i <= S; i++)
        {
            cin >> V[i].first >> V[i].second;
        }

        sort(V + 1, V + S + 1, comp);

        for (int i = 1; i <= S; i++)
        {
            prefix[i] = prefix[i - 1] + V[i].first;
        }
        for (int i = S; i >= 1; i--)
        {
            suffix[i] = suffix[i + 1] + V[i].second;
        }
        
        cout << "Case #" << caseNo << ": ";
        for (int i = 0; i < D; i++)
        {
            int A, B;
            cin >> A >> B;

            if (prefix[S] < A || suffix[1] < B)
            {
                cout << "N";
                continue;
            }

            int l = 1, r = S;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (prefix[mid] < A)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }

            double maxB = (double)(V[l].first - (A - prefix[l - 1])) / V[l].first * V[l].second + suffix[l + 1];
            if (maxB >= B - 1e-5)
            {
                cout << "Y";
            }
            else
            {
                cout << "N";
            }
        }
        cout << endl;
    }
    // system("pause");
}