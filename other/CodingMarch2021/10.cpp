#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
priority_queue<pii, vector<pii>, greater<pii>> que;

int main() {
    cin >> N;
    ll ans = 0, credit = 0;
    for (int i = 0; i < N; i++) {
        ll d, p, x, t;
        cin >> d >> p >> x >> t;
        while (!que.empty() && que.top().first <= d) {
            credit += que.top().second;
            que.pop();
        }
        ans += max(0ll, p - credit);
        credit -= min(credit, p);
        que.push(make_pair(d + t, x));
    }
    cout << ans << endl;
}