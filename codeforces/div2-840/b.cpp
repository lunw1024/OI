#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        vector<pii> a;
        vector<int> h(N);
        vector<int> pp(N);
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> pp[i];
        }
        for (int i = 0; i < N; i++) {
            a.push_back(make_pair(pp[i], h[i]));
        }
        sort(a.begin(), a.end());
        int d = 0, p = 0;
        
        while (K > 0) {
            d += K;
            // cout << "damage = " << d << endl;
            while (p < N && a[p].second <= d) {
                p++;
            }
            if (p == N) {
                break;
            }
            K -= a[p].first;
            // cout << "new k = " << K << endl;
        }
        cout << (p == N ? "YES" : "NO") << endl;
    }

}
