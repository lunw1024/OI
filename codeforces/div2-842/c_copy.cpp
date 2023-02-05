#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ifstream fin("in.txt");
ifstream ansin("ans.txt");

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    fin >> T;
    while (T--) {
        cout << "testing case " << T << endl;
        fin >> N;
        vector<int> p(N), q(N), mx(N);
        vector<bool> vis(N + 1);
        int cur = 1;
        vector<pii> a(N);
        for (int i = 0; i < N; i++) {
            int x = 0;
            fin >> x;
            a[i] = make_pair(x, i);
            mx[i] = x;
        }
        sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 1; i <= N; i++) {
            pii e = a[i - 1];
            int x = e.first, idx = e.second;
            if (x < i) {
                ok = false;
                break;
            }
            p[idx] = i;
            if (x > i) {
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
        }
        if (ok) {
            // cout << "YES" << endl;
            // for (int i : p) {
            //     cout << i << " ";
            // }
            // cout << endl;
            // for (int i : q) {
            //     cout << i << " ";
            // }
            // cout << endl;

            // for (int i = 0; i < N; i++) {
            //     assert(max(p[i], q[i]) == mx[i]);
            // }
            string ans;
            ansin >> ans;
            assert(ans == "YES");
        } else {
            string ans;
            ansin >> ans;
            assert(ans == "NO");
        }
    }
}
