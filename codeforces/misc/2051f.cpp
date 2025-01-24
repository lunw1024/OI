// joker
// for all x < ai, x -> [x, x + 1]
// for all x > ai, x -> [x - 1, x]
// for x == ai, x -> [1, n]
// maintain 3 segments
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<pii> segs;
        segs.push_back(make_pair(m, m));
        bool flag = false;
        for (int j = 0; j < q; j++) {
            int x;
            cin >> x;
            vector<pii> newsegs;
            for (pii p : segs) {
                int l = p.first, r = p.second;
                if (r < x) {
                    newsegs.push_back(make_pair(l, r + 1));
                } else if (x < l) {
                    newsegs.push_back(make_pair(l - 1, r));
                } else {
                    if (flag || l != r) {
                        newsegs.push_back(make_pair(l, r));
                    }
                    if (!flag) {
                        newsegs.push_back(make_pair(1, 1));
                        newsegs.push_back(make_pair(n, n));
                        flag = true;
                    }
                }
            }
            swap(segs, newsegs);
            sort(segs.begin(), segs.end());
            // for (pii p : segs) {
            //     cerr << p.first << ", " << p.second << endl;
            // }
            pii last = segs[0];
            int ans = 0;
            for (int i = 1; i < segs.size(); i++) {
                if (last.second < segs[i].first) {
                    ans += last.second - last.first + 1;
                    last = segs[i];
                } else {
                    last = make_pair(last.first, max(last.second, segs[i].second));
                }
            }
            ans += last.second - last.first + 1;
            cout << ans << " ";
        }
        cout << endl;
    }
}


