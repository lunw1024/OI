#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N), b, r;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            char c;
            cin >> c;
            if (c == 'B')
                b.push_back(a[i]);
            else
                r.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        sort(r.begin(), r.end());
        bool ans = true;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] < i + 1) {
                ans = false;
            }
        }
        for (int i = 0; i < r.size(); i++) {
            if (r[i] > int(b.size() + 1 + i)) {
                ans = false;
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
    cout << endl;
}
