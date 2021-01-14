#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

const int MAXN = (int)2e5 + 1;
const ll INF = (ll)1e16;
vector<int> edges[MAXN];
vector<ll> A(MAXN), low(MAXN);
int N, M;

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        low[i] = INF;
    }
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
    }
    ll ans = -INF;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, A[i] - low[i]);
        for (int j : edges[i])
            low[j] = min(low[j], min(low[i], A[i]));
    }
    cout << ans << endl;
}