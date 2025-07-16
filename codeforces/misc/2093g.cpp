#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <bitset>
#include <array>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int VOCAB_SIZE = 2;
struct Trie {
    vector<array<int, VOCAB_SIZE>> children;
    vector<int> nodes;

    Trie() {
        nodes.push_back(-1);
        children.emplace_back();
    }

    void insert(const string& s, int idx) {
        int p = 0;
        for (char c : s) {
            // cerr << c << ", " << p << ", " << int(c - 'a') << endl;
            if (children[p][c - '0'] <= 0) {
                children[p][c - '0'] = int(nodes.size());
                nodes.push_back(0);
                children.emplace_back();
            }
            p = children[p][c - '0'];

            // custom logic
            nodes[p] = max(nodes[p], idx);
        }
    }

    // custom visit function
    int solve(const string& s, const string& k) {
        // cerr << "s=" << s << ", k=" << k << endl;
        int p = 0;
        int out = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (k[i] == '0') {
                out = max(out, nodes[children[p]['1' - c]]);
            }
            if (children[p][c - '0'] <= 0) {
                return out;
            }
            p = children[p][c - '0'];

        }
        // cerr << "found " << nodes[p] << endl;
        out = max(out, nodes[p]);
        return out;
    }
    
};

void solve() {
    int n, k;
    cin >> n >> k;
    string sk = bitset<30>(k).to_string();
    vi a(n);
    Trie trie;
    const int INF = int(1e9);
    int ans = INF;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        trie.insert(bitset<30>(a[i]).to_string(), i);
        string s = bitset<30>(a[i] ^ k).to_string();
        int res = trie.solve(s, sk);
        if (res >= 0) {
            ans = min(ans, i - res + 1);
        }
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}

