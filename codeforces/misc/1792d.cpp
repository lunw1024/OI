#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> trie, perms(n);
        trie.push_back(vi(m + 1));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int x = 0;
            vi p(m + 1);
            for (int j = 1; j <= m; j++) {
                int k;
                cin >> k;
                p[k] = j;
                perms[i].push_back(k);
            }
            // cerr << "i = " << i << endl;
            for (int j = 1; j <= m; j++) {
                if (trie[x][p[j]] == 0) {
                    trie[x][p[j]] = ++cnt;
                    trie.push_back(vi(m + 1));
                }
                // cerr << "pushing " << p[j] << endl;
                x = trie[x][p[j]];
            }
            
        }
        for (int i = 0; i < n; i++) {
            int x = 0, ans = 0;;
            for (int j = 0; j < m; j++) {
                if (trie[x][perms[i][j]] == 0) {
                    break;
                }
                x = trie[x][perms[i][j]];
                ans++;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}

