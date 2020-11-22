#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)1e5 + 1;
const ll INF = (ll)1e18;
int N;
int E[MAXN], R[MAXN];
priority_queue<pii> good; // (E[i] + R[i], idx)
priority_queue<pii, vector<pii>, greater<pii>> bad; // (idx, E[i])

struct BIT {
    ll data[MAXN];
    inline int lowbit(int x) {
        return x & -x;
    }
    ll query(int x) {
        ll out = 0;
        while (x > 0) {
            out += data[x];
            x -= lowbit(x);
        }
        return out;
    }
    void add(int x, ll k) {
        while (x <= N) {
            data[x] += k;
            x += lowbit(x);
        }
    }
} bit;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        ll ans = 0, sum = 0;
        int cnt = 0, anscnt = 0;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> E[i] >> R[i];
            good.push(make_pair(E[i] + R[i], i));
            sum += E[i];
            bit.add(i, E[i]);
        }
        while (!good.empty()) {
            if (!bad.empty()) {
                pii top = bad.top();
                bad.pop();
                sum -= top.second;
                cnt++;
                bit.add(top.first, -top.second);
            }
            while (!good.empty() && good.top().first > sum) {
                bad.push(make_pair(good.top().second, E[good.top().second]));
                good.pop();
            }
            // calc ans
            if (!good.empty() && bad.empty()) {
                ans = INF, anscnt = cnt;
                break;
            } else if (ans < sum + bit.query(bad.top().first) - bad.top().second) {
                ans = sum + bit.query(bad.top().first) - bad.top().second;
                anscnt = cnt;
            }
        }
        cout << "Case #" << caseNo << ": " << anscnt << " ";
        if (ans == INF)
            cout << "INDEFINITELY" << endl;
        else
            cout << ans << endl;
        
        // clear
        fill(bit.data + 1, bit.data + 1 + N, 0);
        while (!good.empty())
            good.pop();
        while (!bad.empty())
            bad.pop();
    }
}