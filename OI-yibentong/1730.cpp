// http://ybt.ssoier.cn:8088/problem_show.php?pid=1730

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, M;
bool e[301][301 + 1501] = {0};
int vis[301 + 1501] = {0};
int match[301 + 1501] = {0}, tst = 1;
vector<int> edges[301 + 1501];

bool hungary_pair(int x) {
    for (int i = N + 1; i <= N + M; i++) {
        if (e[x][i] && vis[i] != tst) {
            vis[i] = tst;
            if (match[i] == 0 || hungary_pair(match[i])) {
                match[x] = i;
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}


int dfn[301 + 1501] = {0}, low[301 + 1501] = {0}, cnt = 0;
int stk[301 + 1501] = {0}, top = -1;
int scc[301 + 1501] = {0}, total = 0;
bool instack[301 + 1501] = {0};
void tarjan(int u) {
    low[u] = dfn[u] = ++cnt, stk[++top] = u, instack[u] = true;
    for (int i = 0; i < edges[u].size(); i++) {
        int v = edges[u][i];
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        total++;
        while (stk[top] != u) {
            scc[stk[top]] = total;
            instack[stk[top--]] = false;
        }
        scc[stk[top]] = total;
        instack[stk[top--]] = false;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j - 1] == '1')
                e[i][j + N] = true;
        }
    }

    // solve for max pair
    for (int i = 1; i <= N; i++, tst++) {
        if (!hungary_pair(i)) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    cout << 1;
                }
                cout << endl;
            }
            return 0;
        }
    }

    // build graph
    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j <= N + M; j++) {
            if (j == match[i])
                edges[i].push_back(j);
            else if (e[i][j])
                edges[j].push_back(i);
        }
    }

    // additional node
    for (int i = N + 1; i <= N + M; i++) {
        if (match[i] == 0)
            edges[N + M + 1].push_back(i);
        else
            edges[i].push_back(N + M + 1);
    }
    
    // tarjan
    for (int i = 1; i <= N + M + 1; i++) {
        if (dfn[i] == 0)
            tarjan(i);
    }

    // answer
    for (int i = 1; i <= N; i++) {
        for (int j = N + 1; j <= N + M; j++) {
            if (e[i][j] && (match[i] == j || scc[i] == scc[j]))
                cout << 0;
            else
                cout << 1;
        }
        cout << endl;
    }
}
