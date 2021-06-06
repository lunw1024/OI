#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        string s;
        cin >> s;
        vector<int> ans(N + 2), prev(N + 2);
        for (int i = 1; i <= N; i++) {
            ans[i] = s[i - 1] == '1';
        }
        prev = ans;
        for (int i = 0; i < M; i++) {
            bool flag = false;
            for (int j = 1; j <= N; j++) {
                if (ans[j] == 0 && (prev[j - 1] == 0 ^ prev[j + 1] == 0)) {
                    ans[j] = 1;
                    flag = true;
                }
            }
            if (!flag)
                break;
            prev = ans;
        }
        for (int i = 1; i <= N; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
}