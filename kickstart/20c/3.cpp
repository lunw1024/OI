#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, R, C, mat[30][30];
int indegree[26];
bool E[26][26], exist[26];
queue<int> q, ans;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> R >> C;

        fill(&E[0][0], &E[25][26], false);
        fill(exist, exist + 26, false);
        fill(indegree, indegree + 26, 0);
        q = queue<int>();
        ans = queue<int>();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char ch;
                cin >> ch;
                mat[i][j] = ch - 'A';
                exist[ch - 'A'] = true;
            }
        }

        for (int i = 0; i < R - 1; i++) {
            for (int j = 0; j < C; j++) {
                int top = mat[i][j], bot = mat[i + 1][j];
                if (top != bot && !E[bot][top]) {
                    E[bot][top] = true;
                    indegree[top]++;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            if (exist[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        // topo
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (exist[i] && E[top][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0)
                        q.push(i);
                }
            }
            ans.push(top);
        }

        int loop = false;
        for (int i = 0; i < 26; i++) {
            if (exist[i] && indegree[i] > 0) {
                loop = true;
            }
        }

        string s;
        if (loop) {
            s = "-1";
        } else {
            while (!ans.empty()) {
                int top = ans.front();
                ans.pop();
                s.push_back('A' + top);
            }
        }

        cout << "Case #" << caseNo << ": " << s << endl;
    }
}
