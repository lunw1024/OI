#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vec1 = vector<ll>;
using vec2 = vector<vector<ll>>;

const ll INF = ll(1e18);
int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    vec1 F, G; // # f switch needed to get g seats
    ll diff = 0;
    for (int i = 0; i < N; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x > y) {
            diff -= z;
        } else {
            diff += z;
            F.push_back((y - x) / 2 + 1);
            G.push_back(z);
        }
    }
    if (diff < 0) {
        cout << 0 << endl;
        return 0;
    }
    N = F.size();
    // for (int i = 0; i < N; i++) {
    //     cout << F[i] << " " << G[i] << endl;
    // }
    ll need = diff / 2 + 1;
    
    vec2 dp(N + 1, vec1(need + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= need; j++) {
            if (j == 0) {
                dp[i + 1][j] = 0;
            }
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][min(need, j + G[i])] = min(dp[i + 1][min(need, j + G[i])], dp[i][j] + F[i]);
        }
    }
    cout << (dp[N][need]) << endl;
}
