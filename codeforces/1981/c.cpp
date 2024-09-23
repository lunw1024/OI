#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

vector<int> to_bin(int x) {
    int y = x;
    vector<int> out;
    while (x > 0) {
        out.push_back(x & 1);
        x >>= 1;
    }
    reverse(out.begin(), out.end());
    //debug
    // cerr << "bin(" << y << ") = ";
    // for (int x : out) {
    //     cerr << x;
    // }
    // cerr << endl;
    return out;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x != -1) {
                arr.push_back(make_pair(i, x));
            }
        }
        bool ok = true;
        deque<int> ans;
        for (int i = 0; i + 1 < arr.size(); i++) {
            int a = arr[i].second, b = arr[i + 1].second;
            int d = arr[i + 1].first - arr[i].first;
            int common = 0;
            // cerr << "for pair " << a << ", " << b << endl;
            vector<int> a_bin = to_bin(a), b_bin = to_bin(b);
            for (int j = 0; j < min(a_bin.size(), b_bin.size()); j++) {
                if (a_bin[j] == b_bin[j]) {
                    common++;
                } else {
                    break;
                }
            }
            int steps = int(a_bin.size()) + int(b_bin.size()) - common * 2;
            // cerr << "common = " << common << ", step = " << steps << endl;
            if (steps > d || steps % 2 != (d) % 2) {
                ok = false;
                break;
            }
            // construct intermediate steps
            int x = a;
            for (int j = common; j < a_bin.size(); j++) {
                x >>= 1;
                ans.push_back(x);
                // cerr << "add " << x << endl;
            }
            for (int j = common; j < b_bin.size(); j++) {
                x <<= 1;
                x |= b_bin[j];
                ans.push_back(x);
                // cerr << "add " << x << endl;
            }
            for (int j = 0; j < d - steps; j++) {
                if (j % 2) {
                    x >>= 1;
                } else {
                    x <<= 1;
                }
                ans.push_back(x);
                // cerr << "adding filler " << x << endl;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            continue;
        }
        // special case of all 0s.
        if (arr.size() == 0) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i%2 + 1);
            }
        } else {
            // add suffix
            int x = arr.back().second;
            for (int i = arr.back().first + 1; i < n; i++) {
                if (x > 1) {
                    x >>= 1;
                    ans.push_back(x);
                } else {
                    x <<= 1;
                    ans.push_back(x);
                }
            }
            x = arr.front().second;
            ans.push_front(x);
            for (int i = arr.front().first - 1; i >= 0; i--) {
                if (x > 1) {
                    x >>= 1;
                    ans.push_front(x);
                } else {
                    x <<= 1;
                    ans.push_front(x);
                }
            }
        }
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}
