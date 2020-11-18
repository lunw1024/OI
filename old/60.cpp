#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 200003;
int N;
pair<int, int> A[MAXN];
int B[MAXN];
int prefix[MAXN] = {0}, suffix[MAXN] = {0};
int ans[MAXN] = {0};

int main()
{
    cin >> N;
    for (int i = 1; i <= N + 1; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> B[i];
    }
    
    sort(A + 1, A + N + 2);
    sort(B + 1, B + N + 1);

    for (int i = 1; i <= N; i++)
    {
        prefix[i] = max(prefix[i - 1], A[i].first - B[i]);
    }
    for (int i = N + 1; i >= 2; i--)
    {
        suffix[i] = max(suffix[i + 1], A[i].first - B[i - 1]);
    }

    for (int i = 1; i <= N + 1; i++)
    {
        ans[A[i].second] = max(prefix[i - 1], suffix[i + 1]);
    }

    for (int i = 1; i <= N + 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // system("pause");
}