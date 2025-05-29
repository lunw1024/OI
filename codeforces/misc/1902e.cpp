#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int VOCAB_SIZE = 26;
struct Trie {
    vector<array<int, VOCAB_SIZE>> children;
    vector<int> nodes;

    Trie() {
        nodes.push_back(0);
        children.emplace_back();
    }

    void insert(string s) {
        int p = 0;
        for (char c : s) {
            // cerr << c << ", " << p << ", " << int(c - 'a') << endl;
            if (children[p][c - 'a'] <= 0) {
                children[p][c - 'a'] = int(nodes.size());
                nodes.push_back(0);
                children.emplace_back();
            }
            p = children[p][c - 'a'];

            // custom logic
            nodes[p]++;
        }
    }

    ll count(string s) {
        int p = 0;
        ll out = 0;
        for (char c : s) {
            if (children[p][c - 'a'] <= 0) {
                return out;
            }
            p = children[p][c - 'a'];

            out += nodes[p];
        }
        return out;
    }
    
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    Trie trie;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        trie.insert(s[i]);
        reverse(s[i].begin(), s[i].end());
        ans += s[i].size() * n * 2;
    }


    for (string x : s) {
        ans -= 2 * trie.count(x);
    }
    cout << ans << endl;
}

