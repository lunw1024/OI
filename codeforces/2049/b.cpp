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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int firstp = n - 1, lasts = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'p')
                firstp = min(firstp, i);
            else if (s[i] == 's')
                lasts = max(lasts, i);
        }
        if (firstp != n - 1 && lasts != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
