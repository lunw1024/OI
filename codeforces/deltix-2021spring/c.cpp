#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        vector<int> a(N);
        vector<int> level(N);
        stack<int> s;
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = N - 1; i >= 0; i--) {
            s.push(a[i]);
            if (!s.empty() && s.top() == 1) {
                level[i] = 1;
                for (int j = 1; j <= N; j++) {
                    if (!s.empty() && s.top() == j) {
                        // cerr << "popping " << s.top() << endl;
                        s.pop();
                    } else {
                        break;
                    }
                }
            }
        }
        // for (int i : level) {
        //     cerr << i << " ";
        // }
        // cout << endl;
        // output
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (level[i] == 1) {
                ans.push_back(1);
            } else {
                while (a[i] != ans.back() + 1)
                    ans.pop_back();
                ans.back()++;
            }
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j] << (j < ans.size() - 1 ? "." : "\n");
            }
        }
    }
}