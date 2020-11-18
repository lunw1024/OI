#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = (int)5e5 + 1;
int N, A, B, cnt[MAXN];
double prob[MAXN], ans;
vector<int> edges[MAXN], stack;

void dfs(int u, int step) {
    stack.push_back(u);
    for (int v : edges[u])
        dfs(v, step);
    stack.pop_back();
    cnt[u]++;
    if (stack.size() >= step)
        cnt[stack[stack.size() - step]] += cnt[u];
}

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N >> A >> B;
        for (int i = 2; i <= N; i++) {
            int parent;
            cin >> parent;
            edges[parent].push_back(i);
        }
        ans = 0.;
        fill(prob + 1, prob + 1 + N, 0);
        fill(cnt + 1, cnt + 1 + N, 0);
        dfs(1, A);
        for (int i = 1; i <= N; i++)
            prob[i] = (double)cnt[i] / N;
        fill(cnt + 1, cnt + 1 + N, 0);
        dfs(1, B);
        for (int i = 1; i <= N; i++)
            prob[i] = prob[i] + (double)cnt[i] / N - (double)cnt[i] / N * prob[i];
        for (int i = 1; i <= N; i++)
            ans += prob[i];
        cout << "Case #" << caseNo << ": " << ans << endl;
        for (int i = 1; i <= N; i++)
            edges[i].clear();
    }
}