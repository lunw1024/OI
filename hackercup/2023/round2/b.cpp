#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

int sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        int N;
        cin >> N;
        deque<int> a, b;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        int equal_cnt = 0, l = 0, h = 0, inflections = 0, prev_sign = -2;
        vector<int> candidates;
        for (int i = 0; i < N; i++) {
            equal_cnt += a[i] == b[i];
            l += a[i] < b[i];
            h += a[i] > b[i];
            int s = sign(a[i] - b[i]);
            if (s != prev_sign) {
                inflections++;
                candidates.push_back(i);
                // cerr << "adding candidate " << i << endl;
            }
            prev_sign = s;
        }
        if (equal_cnt > N % 2 || inflections > 3) {
            // cerr << equal_cnt << " " << inflections << endl;
            cout << "Case #" << task << ": " << -1 << endl;
            continue;
        }
        // brute force each candidate by simming 2n steps
        int ans = 0;
        for (int i = 0; i < 2 * N; i++) {
            bool possible = false;
            for (int c : candidates) {
                possible |= (N % 2 == 0 && c == N / 2);
                possible |= (N % 2 == 1 && (c == N / 2 || c == N / 2 + 1));
            }
            if (possible) {
                // check
                bool good = true;
                for (int j = 0; j < N; j++) {
                    if (j < N / 2) {
                        good &= a[j] < b[j];
                    } else if (j > N / 2 || (N % 2 == 0 && j == N / 2)) {
                        good &= a[j] > b[j];
                    }
                    good &= a[j] == b[N - j - 1];
                    if (!good) {
                        break;
                    }
                }
                if (good) {
                    break;
                }
            }
            a.push_back(b.front());
            b.push_back(a.front());
            a.pop_front();
            b.pop_front();
            assert(a.size() == b.size() && a.size() == N);
            for (int j = 0; j < candidates.size(); j++) {
                candidates[j] = candidates[j] == 0 ? N - 1 : candidates[j] - 1;
            }
            ans++;
            if (ans == 2 * N) {
                ans = -1;
            }
        }
        cout << "Case #" << task << ": " << ans << endl;
    }
}
