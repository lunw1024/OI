#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)262146;
int N, arr[MAXN], nxt[MAXN][59];
int ans = -1;
ifstream cin("262144.in");
ofstream cout("262144.out");

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        fill(&nxt[i][0], &nxt[i][x], -1);
        nxt[i][x] = i + 1;
    }
    fill(&nxt[N + 1][0], &nxt[N + 1][59], -1);
    for (int k = 2; k <= 58; k++) {
        for (int i = 1; i <= N; i++) {
            if (nxt[i][k] == 0) {
                if (nxt[i][k - 1] == -1)
                    nxt[i][k] = -1;
                else
                    nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
            }
        }
    }
    for (int k = 58; ans == -1 && k >= 0; k--) {
        for (int i = 1; ans == -1 && i <= N; i++) {
            if (nxt[i][k] > 0)
                ans = k;
        }
    }
    cout << ans << endl;
}