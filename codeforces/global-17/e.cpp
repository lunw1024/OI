// Lemma 1: goodness == (WLOG a[0] == 0) [0, 1, 2, 4, ...]: a[i] must >= 2 * a[i-1]
// The problem is eqv to the longest subseq that satisfy Lemma 1
// Greedy: If can append, must append
// Maxlen is O(log(N))
// Try every starting element

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        vector<ll> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (i > 0 && v[i] == v[i - 1])
                continue;
            int p = i, l = 1;
            while (p < N - 1 && v[p + 1] == v[p])
                p++, l++;
            ll d = 1;
            p = lower_bound(v.begin(), v.end(), v[i] + d) - v.begin();
            // cout << "pick " << p << " ";
            while (p < N) {
                l++;
                d = 2 * (v[p] - v[i]);
                p = lower_bound(v.begin(), v.end(), v[i] + d) - v.begin();
                // cout << p << " ";
            }
            // cout << endl;
            ans = max(ans, l);
        }
        cout << N - ans << endl;
    }
}