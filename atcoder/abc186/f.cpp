#include <iostream>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using pii = pair<int, int>;
using ll = long long;

int N, H, W;
vector<pii> obs;
fenwick_tree<int> bit((int)2e5 + 2);

int main() {
    cin >> H >> W >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        obs.push_back(make_pair(x, y));
    }
    sort(obs.begin(), obs.end());

    // special
    bool xf = false;
    for (int i = 0; i < N; i++) {
        int x = obs[i].first, y = obs[i].second;
        if (!xf && x == 1) {
            for (int j = y + 1; j <= W; j++)
                obs.push_back(make_pair(1, j));
            xf = true;
        }
        if (y == 1) {
            for (int j = x + 1; j <= H; j++) {
                obs.push_back(make_pair(j, 1));
            }
            break;
        }
    }
    sort(obs.begin(), obs.end());

    ll ans = (ll)H * W;
    int last = 0;
    for (pii e : obs) {
        int x = e.first, y = e.second;

        if (x > last)
            ans -= 1 + bit.sum(y + 1, W + 1); // +1 for y == W
        else
            ans -= (bit.sum(y, y + 1) == 0);
        if (bit.sum(y, y + 1) == 0) {
            bit.add(y, 1);
        }
        last = x;
    }
    cout << ans << endl;
}