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
        vector<int> a(N), cnt(33), L(33), R(33);
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
            if (x == y + 1) {
                if (avg > a[i]) {
                    R[y]++;
                } else {
                    L[y]--;
                }
            }
        }
        for (int i = 0; i < 32; i++) {
            // cout << cnt[i] << " [" << cnt[i] + L[i] * 2 << ", " << cnt[i] + R[i]*2 << "]" << endl;
            if (cnt[i] % 2 == 1) {
                ok = false;
                break;
            }
            if (cnt[i] / 2 + L[i] <= 0 && cnt[i] / 2 + R[i] >= 0) {
                cnt[i + 1] += cnt[i] / 2;
            } else {
                ok = false;
                break;
            }
        }
        ok &= cnt[32] == 0;
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
