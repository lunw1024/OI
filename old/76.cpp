#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9 + 7;
int N;
vector<int> row[20001];
vector<int> col[20001];
map<pair<int, int>, pair<int, int> > component;
ll ans = 0;
ifstream fin("triangles.in");
ofstream fout("triangles.out");

int main()
{
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        fin >> x >> y;
        x += 10000, y += 10000;
        row[x].push_back(y);
        col[y].push_back(x);
    }

    for (int i = 0; i <= 20000; i++)
    {
        sort(row[i].begin(), row[i].end());
        sort(col[i].begin(), col[i].end());
    }

    for (int i = 0; i <= 20000; i++)
    {
        int sum = 0, prefix = 0, n = row[i].size();
        for (int j = 0; j < n; j++)
            sum += row[i][j];
        
        for (int j = 0; j < n; j++)
        {
            int coef = (row[i][j] * j - prefix) + (sum - prefix - row[i][j] - row[i][j] * (n - j - 1));
            // cout << "insert " << coef << " into (" << i << ", " << row[i][j] << ")" << endl;
            pair<int, int> idx = make_pair(i, row[i][j]);
            component[idx] = make_pair(coef, 0);
            prefix += row[i][j];
        }
    }

    for (int i = 0; i <= 20000; i++)
    {
        int sum = 0, prefix = 0, n = col[i].size();
        for (int j = 0; j < n; j++)
            sum += col[i][j];
        
        for (int j = 0; j < n; j++)
        {
            int coef = (col[i][j] * j - prefix) + (sum - prefix - col[i][j] - col[i][j] * (n - j - 1));
            // cout << "insert " << coef << " into (" << col[i][j] << ", " << i << ")" << endl;
            pair<int, int> idx = make_pair(col[i][j], i);
            component[idx].second = coef;
            prefix += col[i][j];
        }
    }

    for (map<pair<int, int>, pair<int, int> >::iterator it = component.begin(); it != component.end(); it++)
    {
        pair<int, int> obj = (*it).second;
        // cout << obj.first << " " << obj.second << endl;
        ans = (ans + 1ll * obj.first * obj.second) % MOD;
    }
    fout << ans << endl;
    // system("pause");
}
