#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int q(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int a;
    cin >> a;
    return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        set<int> candidates, new_candidates;
        for (int i = 1; i <= n; i++) {
            candidates.insert(i);
        }
        while (candidates.size() > 2) {
            auto it = candidates.begin();
            int a = *it;
            int b = *next(it);
            int c = *next(next(it));
            int x = q(a, b);
            int y = q(b, c);
            if (x == y) {
                candidates.erase(b);
            } else if (x > y) {
                candidates.erase(c);
            } else {
                candidates.erase(a);
            }
            // int anchor = *candidates.begin();
            // vector<pii> a;
            // int maximum = 0;
            // for (set<int>::const_iterator it = next(candidates.begin()); it != candidates.end(); it++) {
            //     int gcd = q(anchor, *it);
            //     a.emplace_back(gcd, *it);
            //     maximum = max(maximum, gcd);
            // }
            // new_candidates.clear();
            // for (auto [gcd, candidate] : a) {
            //     if (gcd == maximum) {
            //         new_candidates.insert(candidate);
            //     }
            // }
            // if (new_candidates.size() == 1) {
            //     new_candidates.insert(anchor);
            // }
            // swap(candidates, new_candidates);
        }
        assert(candidates.size() == 2);
        // cerr << "hi" << endl;
        int x = *(candidates.begin()), y = *(next(candidates.begin()));
        cout << "! " << x << " " << y << endl;
        int verdict;
        cin >> verdict;
        if (verdict != 1) {
            return 0;
        }
        
    }
}

