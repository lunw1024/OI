#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vector<int> a(N);
        vector<pii> p(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            p[i] = make_pair(a[i], i);
        }
        sort(p.begin(), p.end());
        int s = 0, w = 0;
        for (pii e : p) {
            if (e.first + s > M) {
                break;
            }
            s += e.first;
            w++;
        }
        bool beatw = false, beatw1 = false;
        for (int i = 0; i < w; i++) {
            pii e = p[i];
            if (e.second == w) {
                beatw = true;
            }
            if (e.second == w + 1) {
                beatw1 = true;
            }
        }
        if (w >= N - 1) {
            // w + 1 doesn't exist
            beatw1 = true;
        }
        if (w >= N) {
            // w doesn't exist
            beatw = true;
        }
        int ans = max(1, N - w);
        // cerr << "wins = " << w << ", inital ans = " << ans << ", " << beatw << beatw1 << endl;

        int x = w - 1;
        while (x >= 0 && (p[x].second == w || p[x].second == w + 1)) {
            x--;
        }
        // cerr << "x = " << x << endl;
        if (!beatw) {
            ans++;
            if (x >= 0 && s - p[x].first + a[w] <= M) {
                // cerr << "swiching with" << x << endl;
                ans--;
                x--;
            }
        }
        while (x >= 0 && (p[x].second == w || p[x].second == w + 1)) {
            x--;
        }
        // cerr << "x = " << x << endl;
        if (!beatw1) {
            if (x >= 0 && s - p[x].first + a[w + 1] <= M) {
                // cerr << "swiching with" << x << endl;
                ans--;
            }
        }
        // int ans1 = N + 1, s1 = 0;
        // if (!beatw && a[w] <= M) {
        //     ans1 -= 1;
        //     s1 += a[w];
        //     for (pii e : p) {
        //         if (e.second == w) {
        //             continue;
        //         }
        //         if (e.first + s1 > M) {
        //             break;
        //         }
        //         s1 += e.first;
        //         ans1--;
        //     }
        //     if (N + 1 - ans1 != w) {
        //         ans1 = N + 1;
        //     }
        //     ans1 -= 1;
        // }

        // int ans2 = N + 1, s2 = 0;
        // if (!beatw1 && a[w + 1] <= M) {
        //     ans2 -= 1;
        //     s2 += a[w + 1];
        //     for (pii e : p) {
        //         if (e.second == w + 1) {
        //             continue;
        //         }
        //         if (e.first + s2 > M) {
        //             break;
        //         }
        //         s2 += e.first;
        //         ans2--;
        //     }
        //     if (N + 1 - ans2 != w) {
        //         ans2 = N + 1;
        //     }
        //     ans2 -= 2;
        // }
        // int ans3 = N + 1, s3 = 0;
        // if (!beatw1 && !beatw && a[w] + a[w + 1] <= M) {
        //     ans3 -= 2;
        //     s3 += a[w + 1] + a[w];
        //     for (pii e : p) {
        //         if (e.second == w + 1 || e.second == w) {
        //             continue;
        //         }
        //         if (e.first + s1 > M) {
        //             break;
        //         }
        //         s3 += e.first;
        //         ans3--;
        //     }
        //     if (N + 1 - ans3 == w) {
        //         ans3 = N + 1;
        //     }
        //     ans3 -= 2;
        // }

        // int switched = w;
        // // if can't beat w
        // int ans1 = 0;
        // if (!beatw) {
        //     // search for player that's != w or w+1 and can be switched
        //     // for (int i = w - 1; i >= 0; i--) {
        //     //     pii e = p[i];
        //     //     if (e.second != w && e.second != w + 1 && s - e.first + a[w] <= M) {
        //     //         s -= e.first;
        //     //         s += a[w];
        //     //         switched = i;
        //     //         ans--;
        //     //         break;
        //     //     }
        //     // }
        //     if (M >= a[w]) {
        //         ans1++;
        //     }
        // }
        // // if can't beat w+1
        // if (!beatw1) {
        //     for (int i = switched - 1; i >= 0; i--) {
        //         pii e = p[i];
        //         if (e.second != w && e.second != w + 1 && s - e.first + a[w + 1] <= M) {
        //             s -= e.first;
        //             s += a[w];
        //             ans--;
        //             break;
        //         }
        //     }
        // }
        // cout << ans << ", " << ans1 << ", " << ans2 << ", " << ans3 << endl;
        cout << ans << endl;
    }
}
