#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int N;
ll X, D, ans = 0;
map<ll, vector<P>> seg;

int main() {
    cin >> N >> X >> D;
    if (D == 0) {
        cout << N + 1 << endl;
        return 0;
    }

    // normalize
    if (D < 0) {
        X = X + (N - 1) * D;
        D = -D;
    }
    X -= D; // a_0

    // build segments
    for (int k = 0; k <= N; k++) {
        ll base = k * X, l = (ll)k * (k + 1) / 2, r = (ll)k * N - (ll)k * (k - 1) / 2;
        ll offset = base / D;
        seg[(base % D + D) % D].push_back(make_pair(l + offset, r + offset));
    }

    // aggregate answer
    for (auto& p : seg) {
        // cout << "base = " << p.first << endl;
        vector<P>& v = p.second;
        sort(v.begin(), v.end());
        ll s = v.front().first, t = v.front().second;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > t) {
                ans += t - s + 1;
                s = v[i].first, t = v[i].second;
            } else {
                t = max(t, v[i].second);
            }
        }
        ans += t - s + 1;
        
        // for (P p : v) {
        //     cout << "(" << p.first << " " << p.second << ") ";
        // }
        // cout << endl;
    }

    cout << ans << endl;
}