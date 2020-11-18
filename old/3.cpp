#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int A, B, N, M;
vector<int> rows, cols;
ifstream fin("fencedin.in");
ofstream fout("fencedin.out");

int main()
{
    fin >> A >> B >> N >> M;
    rows.push_back(0);
    cols.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int x;
        fin >> x;
        rows.push_back(x);
    }
    for (int i = 0; i < M; i++)
    {
        int x;
        fin >> x;
        cols.push_back(x);
    }
    rows.push_back(A);
    cols.push_back(B);

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    for (int i = 0; i < rows.size() - 1; i++)
    {
        rows[i] = rows[i + 1] - rows[i];
    }
    for (int i = 0; i < cols.size() - 1; i++)
    {
        cols[i] = cols[i + 1] - cols[i];
    }

    rows.pop_back();
    cols.pop_back();
    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    long long ans = 1ll * rows[0] * M + 1ll * cols[0] * N;
    int r = 1, c = 1;
    while (r <= N && c <= M)
    {
        if (rows[r] < cols[c])
        {
            ans += rows[r] * (M + 1 - c);
            r++;
        }
        else
        {
            ans += cols[c] * (N + 1 - r);
            c++;
        }
    }
    fout << ans << endl;
    // system("pause");
}