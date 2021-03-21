// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, cnt = 0;
vector<int> ans;

int query(int x) {
    cout << x << endl;
    int ret;
    cin >> ret;
    cnt++;
    return ret;
}

int main() {
    int T;
    cin >> T >> N;
    ans.resize(N + 1);
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        fill(ans.begin(), ans.end(), 0);
        cnt = 1;
        int ind1 = 0, ind2 = 0;
        for (int i = 1; i <= N / 2; i++) {
            if (cnt % 10 == 1) {
                if (ind1 > 0 && query(ind1) != ans[ind1]) {
                    for (int j = 1; j <= N; j++)
                        ans[j] ^= 1;
                }
                if (ind2 > 0 && query(ind2) != ans[ind2]) {
                    reverse(ans.begin() + 1, ans.end());
                }
                if (cnt % 2 == 0)
                    query(1); // oddity
            }
            ans[i] = query(i);
            ans[N + 1 - i] = query(N + 1 - i);
            if (ans[i] == ans[N + 1 - i])
                ind1 = i;
            else
                ind2 = i;
        }
        for (int i = 1; i <= N; i++)
            cout << ans[i];
        cout << endl;
        char result;
        cin >> result;
        if (result == 'N')
            return 0;
    }
}
