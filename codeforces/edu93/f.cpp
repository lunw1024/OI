#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)1e6 + 1, INF = (int)1e9 + 1;
int N;
string s;
int nxt[2][MAXN], ans[MAXN];
vector<int> p[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> s;
    int len0 = 0, len1 = 0;
    for (int i = N - 1; i >= 0; i--) {
        nxt[0][i] = s[i] != '0' ? nxt[0][i + 1] + 1 : 0;
        nxt[1][i] = s[i] != '1' ? nxt[1][i + 1] + 1 : 0;
    }

    for (int x = 1; x <= N; x++) {
        p[0].clear();
        p[1].clear();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= 1; j++)
                if (nxt[j][i] >= x)
                    p[j].push_back(i);
        }

        int prev = 0;
        vector<int>::iterator it[2] = {p[0].begin(), p[1].begin()};
        while (prev < N && (it[0] != p[0].end() || it[1] != p[1].end())) {
            for (int i = 0; i <= 1; i++)
                while (it[i] != p[i].end() && *it[i] < prev)
                    it[i]++;
            if (it[0] != p[0].end() && *it[0] == prev || it[1] != p[1].end() && *it[1] == prev)
                prev += x, ans[x]++;
            else
                prev = min(it[0] != p[0].end() ? *it[0] : INF, it[1] != p[1].end() ? *it[1] : INF);
        }
    }
    
    for (int x = 1; x <= N; x++)
        cout << ans[x] << " ";
    cout << endl;
}