#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int minimum = 0, maximum = 0;
    for (int t = 0; t < n; t++) {
        string s;
        cin >> s;
        int ones = 0;
        for (char c : s) {
            ones += c == '1';
        }
        int lb = m / 4, ub = 0;
        int p = 0;
        while (p < m - 1 && ub < m / 4) {
            if (s[p] == '1' && s[p + 1] == '1') {
                ub++;
                p += 2;
            } else {
                p += 1;
            }
        }
        p = 0;
        while (p < m - 1 && lb > 0) {
            if (!(s[p] == '1' && s[p + 1] == '1')) {
                lb--;
                p += 2;
            } else {
                p += 1;
            }
        }
        minimum += ones - ub;
        maximum += ones - lb;
    }

    cout << minimum << " " << maximum;
}

