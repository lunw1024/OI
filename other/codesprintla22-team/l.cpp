// rolling hashing
// hash(a) = a_0 + a_1 * p + a_2 * p^2 + ...
// hash(s[l:r]) = (pre(r) - pre(l - 1)) * inv(p^l)
// hash(s[l:r]) = hash(s[l - 1:r - 1] - a_l) * inv(p) + p^[r - l]

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ull B = ull(1e9 + 7);
int N, M;
vector<string> songs;
vector<ull> powB;

bool solve(int k) {
    cerr << "searching k = " << k << endl;
    unordered_map<ull, int> cnt;
    for (string s : songs) {
        unordered_set<ull> st;
        ull hash = 0;
        for (int i = 0; i < k; i++) {
            hash *= B;
            hash += s[i];
        }
        st.insert(hash);
        for (int i = k; i < N + k - 1; i++) {
            hash = (hash - s[i - k] * powB[k - 1]) * B + s[i];
            st.insert(hash);
        }
        for (ull x : st) {
            cerr << s << ": " << x << endl;
            if (cnt.count(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }
        }
    }
    int ok = 0, total = 0;
    for (pair<ull, int> e : cnt) {
        cerr << e.first << ":" << e.second << endl;
        if (e.second == 1) {
            ok++;
        }
        total += e.second;
    }
    return ok * 2 >= total;
}


int main() {
    cin >> N >> M;
    songs.resize(M);
    powB.resize(N + 1);
    powB[0] = 1;
    for (int i = 1; i <= N; i++)
        powB[i] = powB[i - 1] * B;

    string suffix = string(N, '*');
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        songs[i] = s + suffix;
    }

    // bin search on k
    int l = 0, r = N + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (solve(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int ans = r;
    cout << ans << endl;
}



