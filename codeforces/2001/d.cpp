#include <iostream>
#include <set>
#include <vector>
#include <cassert>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int m = 0;
        vector<int> a(n + 1), last_obs(n + 1), vis(n + 1), unique;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (last_obs[a[i]] == 0) {
                m++;
                unique.push_back(a[i]);
            }
            last_obs[a[i]] = i;
        }

        multiset<int> last, first;
        for (int x : unique) {
            last.insert(last_obs[x]);
            // cerr << "insert " << last_obs[x] << endl;
        }

        vector<int> ans;
        int last_p = 0, p = 0, move_to;
        for (int i = 0; i < m; i++){
            move_to = *last.begin();
            // cerr << "move to " << move_to << endl;
            for (; last_p <= move_to; last_p++) {
                // cerr << "moving past " << a[last_p] << endl;
                if (vis[a[last_p]]) {
                    continue;
                }
                first.insert(a[last_p]);
            }
            // cerr << "first.size = " << first.size() << endl;
            int best;
            if (i % 2 == 0) {
                best = *first.rbegin();
            } else {
                best = *first.begin();
            }
            // cerr << "best = " << best << endl;
            while (a[p] != best) {
                if (!vis[a[p]]) {
                    first.erase(first.find(a[p]));
                }
                p++;
            }
            ans.push_back(best);
            // cerr << "ans += " << best << endl;
            assert(a[p] == best);
            // remove element from consideration
            first.erase(best);
            last.erase(last.find(last_obs[best]));
            vis[best] = true;
            // cerr << "done" << endl;
        }

        // print ans
        cout << m << endl;
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
