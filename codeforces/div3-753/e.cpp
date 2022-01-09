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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int x = 0, y = 0, d = 0, xmax = 0, xmin = 0, ymax = 0, ymin = 0;
        int a = 0, b = 0;
        for (char c : s) {
            int dx = 0, dy = 0;
            if (c == 'D')
                dx = 1, dy = 0;
            if (c == 'U')
                dx = -1, dy = 0;
            if (c == 'R')
                dx = 0, dy = 1;
            if (c == 'L')
                dx = 0, dy = -1;
            x += dx, y += dy;
            xmax = max(xmax, x);
            ymax = max(ymax, y);
            xmin = min(xmin, x);
            ymin = min(ymin, y);

            if (xmax - xmin >= n || ymax - ymin >= m) {
                if (c == 'D')
                    xmax--;
                if (c == 'U')
                    xmin++;
                if (c == 'R')
                    ymax--;
                if (c == 'L')
                    ymin++;
                a = n - xmax, b = m - ymax;
                break;
            } else {
                a = n - xmax, b = m - ymax;
            }
            d++;
        }
        cout << a << " " << b << "\n";
    }
    cout << endl;
}

