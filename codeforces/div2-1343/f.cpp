#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int N;
list<vector<int>> segs;
int cnt[200], cnt1[200];

bool solve(list<vector<int>> segs, vector<int>& ans) {
    for (int i = 1; i < N - 1; i++) {
        int prev = ans.back();
        list<vector<int>>::iterator it;
        bool flag = true;
        for (it = segs.begin(); it != segs.end(); it++) {
            for (int j : *it) {
                if (j == prev) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }

        for (int j : *it)
            if (--cnt[j] <= 1 && j != prev && prev == ans.back()) {
                ans.push_back(j);
            }
        if (prev == ans.back())
            return false;
        segs.erase(it);
    }

    // last two digits
    ans.pop_back();
    vector<int> last = segs.front();
    if (cnt1[last[0]] < cnt1[last[1]])
        swap(last[0], last[1]);
    ans.push_back(last[0]);
    ans.push_back(last[1]);

    reverse(ans.begin(), ans.end());
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        segs.clear();
        cin >> N;
        for (int i = 0; i < N - 1; i++) {
            int n;
            cin >> n;
            vector<int> v;
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                a--;
                v.push_back(a);
            }
            segs.push_back(v);
        }

        vector<int> ans;
        // find the first one
        fill(cnt, cnt + N, 0);
        fill(cnt1, cnt1 + N, 0);
        for (vector<int>& seg : segs)
            for (int j : seg)
                cnt[j]++, cnt1[j]++;

        for (int i = 0; i < N; i++) {
            if (cnt[i] == 1 && ans.empty()) {
                ans.push_back(i);
                // cout << "try entry point " << ans[0] + 1 << endl;
                if (solve(segs, ans)) {
                    break;
                } else {
                    ans.clear(); // try another entry point
                    copy(cnt1, cnt1 + N, cnt);
                }
            }
        }
        
        for (int i : ans)
            cout << i + 1 << " ";
        cout << endl;
    }
}