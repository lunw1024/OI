#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        ll sum = 0;
        vector<int> a(N), cnt(32);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % N != 0) {
            cout << "No" << endl;
            continue;
        }
        int avg = sum / N;
        bool ok = true;
        for (int i = 0; i < N; i++) {
            int d = abs(avg - a[i]);
            if (d == 0) {
                continue;
            }
            int x = 0, y = 0;
            while (d % 2 == 0) {
                y++;
                d /= 2;
            }
            d += 1;
            x = y;
            while (d % 2 == 0) {
                x++;
                d /= 2;
            }
            // cout << abs(avg - a[i]) << " " << d << " " << x << " " << y << endl;
            if (d != 1) {
                ok = false;
                break;
            }
            assert(abs(avg - a[i]) == (1<<x)-(1<<y));
            if (avg > a[i]) {
                cnt[x] += 1;
                cnt[y] -= 1;
            } else if (avg < a[i]) {
                cnt[y] += 1;
                cnt[x] -= 1;
            }
        }
        for (int i = 0; i < 32; i++) {
            if (cnt[i] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
