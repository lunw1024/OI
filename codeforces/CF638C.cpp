#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int N, K;
int arr[(int)1e5 + 1];

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        string s, ans;
        cin >> N >> K >> s;
        sort(s.begin(), s.end());
        if (s[0] < s[K - 1]) {
            ans.push_back(s[K - 1]);
        }

        if (ans.empty()) {
            ans.push_back(s[0]);
            bool flag = true;
            for (int i = K + 1; i < N; i++) {
                if (s[i] != s[i - 1]) {
                    flag = false;
                }
            }
            if (flag) {
                for (int i = K; i < N; i += K) {
                    ans.push_back(s[i]);
                }
            } else {
                ans = ans + s.substr(K);
            }
        }
        cout << ans << endl;
    }
    // system("pause");
}