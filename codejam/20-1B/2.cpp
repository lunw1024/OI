#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;
using ll = long long;

const int INF = int(1e9);
int N, A, B;
bool active = true;

int query(int x, int y) {
    if (!active)
        return 0;
    cout << x << " " << y << endl;
    string response;
    cin >> response;
    // if (true) {
    //     cerr << response << " received in query (" << x << ", " << y << endl;
    // }
    if (response == "CENTER") {
        active = false;
        return 2;
    } else if (response == "HIT")
        return 1;
    else
        return 0;
}

int main() {
    int T;
    cin >> T >> A >> B;
    for (int t = 1; t <= T; t++) {
        active = true;
        
        // grid search
        int hitx = -INF-1, hity = -INF-1;
        for (int x = -INF / 2; active && x <= INF / 2; x += INF / 2) {
            for (int y = -INF / 2; active && y <= INF / 2; y += INF / 2) {
                int response = query(x, y);
                if (response == 1)
                    hitx = x, hity = y;
            }
        }

        // horizontal search
        // left
        int l = -INF, r = hitx-1;
        while (active && l <= r) {
            int mid = (l + r) / 2;
            if (query(mid, hity) == 1)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int ax = l, ay = hity;
        cerr << "left search finished" << endl;
        // right
        l = hitx+1, r = INF;
        while (active && l <= r) {
            int mid = (l + r) / 2;
            if (query(mid, hity) == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        int bx = r, by = hity;
        int ansx = (ax + bx) / 2;
        cerr << "right search finished" << endl;

        // vertical search
        // up
        l = hity+1, r = INF;
        while (active && l <= r) {
            int mid = (l + r) / 2;
            if (query(ansx, mid) == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        int cx = ansx, cy = r;
        cerr << "up search finished" << endl;

        // down
        l = -INF, r = hitx-1;
        while (active && l <= r) {
            int mid = (l + r) / 2;
            if (query(ansx, mid) == 1)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int ex = ansx, ey = l;
        int ansy = (cy + ey) / 2;
        cerr << "down search finished" << endl;
        
        // guess
        int step = 1, sign = 1;
        const int dx[2] = {1, 0}, dy[2] = {0, 1};
        while (active) {
            for (int j = 0; active && j <= 1; j++) {
                for (int i = 1; active && i <= step; i++) {
                    query(ansx, ansy);
                    ansx += sign * dx[j], ansy += sign * dy[j];
                }
            }
            step += 1;
            sign *= -1;
        }
    }
    return 0;
}

