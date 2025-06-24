// greedy
// if first letter is b:
// try b->a, otherwise try b->c->a (but hard to count the valid ops)
// how to count the valid ops?
// c -> a, c -> b -> a, c -> b
// when i use a c -> a how do i know if i break one b->c->a?
// iff cnt(ca) == cnt(b->c->a), we need to break one
// 
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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        int ba = 0, ca = 0, cb = 0, bc = 0, bca = 0, cba = 0;
        for (int i = 0; i < q; i++) {
            char x, y;
            cin >> x >> y;
            if (x == 'a') {
                continue;
            }
            ba += x == 'b' && y == 'a';
            ca += x == 'c' && y == 'a';
            cb += x == 'c' && y == 'b';
            bc += x == 'b' && y == 'c';
            if (x == 'c' && y == 'a') {
                bca = min(bca + 1, bc);
            }
            if (x == 'b' && y == 'a') {
                cba = min(cba + 1, cb);
            }
        }
        for (char& x : s) {
            if (x == 'b') {
                if (ba) {
                    ba--;
                    x = 'a';
                } else if (bca && ca && bc) {
                    x = 'a';
                    bca--;
                    ca--;
                    bc--;
                }
            } else if (x == 'c') {
                if (ca) {
                    ca--;
                    x = 'a';
                } else if (cba && ba && cb) {
                    cba--;
                    ba--;
                    cb--;
                    x = 'a';
                } else if (cb) {
                    cb--;
                    x = 'b';
                }
            }
        }
        cout << s << endl;
    }
}

