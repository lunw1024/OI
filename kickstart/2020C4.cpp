#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int ZERO = (int)1e7 + 1; // 0: 1e7 + 1
int N, MAXN;
int cnt[(int)2e7 + 1] = {0};

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        ll ans = 0;
        cin >> N;
        MAXN = N * 100;
        fill(cnt + ZERO - MAXN, cnt + ZERO + MAXN, 0);
        int pre = 0;
        cnt[ZERO] = 1;
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            pre += a;
            for (int p = 0; pre - p * p >= -MAXN; p++) {
                ans += cnt[pre - p * p + ZERO];
            }
            cnt[pre + ZERO]++;
        }

        cout << "Case #" << caseNo << ": " << ans << endl;
    }
}
