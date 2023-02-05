#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
// ifstream fin("in.txt");

bool comp(pii a, pii b) {
    return a.first == b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        // cout << "testing case " << T << endl;
        cin >> N;
        vector<int> p(N), q(N);
        vector<bool> vis(N + 1), vis1(N + 1);
        int cur = 1;
        vector<pii> a(N), b(N);
        for (int i = 0; i < N; i++) {
            int x = 0;
            cin >> x;
            a[i] = make_pair(x, i);
            b[i] = make_pair(x, i);
            // cout << x << " ";
        }
        // cout << endl;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        auto end = unique(b.begin(), b.end(), comp);
        for (auto it = b.begin(); it != end; it++) {
            pii e = *it;
            int x = e.first, idx = e.second;
            // cerr << "p[" << idx << "] = " << x << endl;
            p[idx] = x;
            vis1[x] = true;
        }
        int cur1 = 1;
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            pii e = a[i - 1];
            int x = e.first, idx = e.second;
            if (x < i) {
                ok = false;
                break;
            }
            if (x > p[idx]) {
                if (!vis[x]) {
                    q[idx] = x;
                    vis[x] = true;
                } else {
                    ok = false;
                    break;
                }
            } else {
                while (cur <= N && vis[cur]) {
                    cur++;
                }
                q[idx] = cur;
                vis[cur] = true;
            }
            // cerr << "p[" << idx << " == " << p[idx] << endl;
            if (p[idx] == 0) {
                while (cur1 <= N && vis1[cur1]) {
                    cur1++;
                }
                // cerr << "p[" << idx << "] = " << cur1 << endl;
                p[idx] = cur1;
                vis1[cur1] = true;
            }
        }
        if (ok) {
            cout << "YES" << endl;
            for (int i : p) {
                cout << i << " ";
            }
            cout << endl;
            for (int i : q) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
// 3 4 4 5 5
// 3 1 4 2 5
// 1 4 2 5 3