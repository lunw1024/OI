#include <iostream>
#include <map>
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
        map<int, int> row, diag;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            row[x] += 1;
            diag[x + y] += 1;
        }
        int x = 0, y = 0;
        for (pii p : row) {
            if (p.second % 2 == 1) {
                x = p.first;
                break;
            }
        }
        for (pii p : diag) {
            if (p.second % 2 == 1) {
                y = p.first - x;
                break;
            }
        }
        cout << x << " " << y << endl;
    }
}

