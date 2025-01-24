#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int q = 0; q < T; q++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        queue<int> a, b, c;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                a.push(i);
            } else if (s[i] == 'b') {
                b.push(i);
            } else {
                c.push(i);
            }
        }
        bool ans = true;
        for (char ch : t) {
            int aa = a.empty() ? n : a.front();
            int bb = b.empty() ? n : b.front();
            int cc = c.empty() ? n : c.front();
            if (ch == 'a') {
                if (aa >= bb || aa >= cc) {
                    ans = false;
                    break;
                } else {
                    a.pop();
                }
            } else if (ch == 'b') {
                if (bb >= cc) {
                    ans = false;
                    break;
                } else {
                    b.pop();
                }
            } else if (ch == 'c') {
                if (cc >= aa) {
                    ans = false;
                    break;
                } else {
                    c.pop();
                }
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}

