#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = (int)2e5 + 1;
int N, K, A[MAXN];
ll ans = (ll)1e18;
vector<pair<int, int>> arr;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    for (int i = 0; i < N; i++) {
        if (i == 0 || A[i] != A[i - 1])
            arr.push_back(make_pair(A[i], 1));
        else
            arr.back().second++;
        // if already satisfied
        if (arr.back().second >= K) {
            cout << 0 << endl;
            return 0;
        }
    }
    // ->
    int cnt = arr[0].second;
    ll cost = 0;
    for (int i = 1; i < arr.size(); i++) {
        cost += (ll)cnt * (arr[i].first - arr[i - 1].first);
        cnt += arr[i].second;
        if (cnt >= K) {
            cost -= cnt - K;
            break;
        }
    }
    ans = min(ans, cost);

    // <-
    cnt = arr.back().second;
    cost = 0;
    for (int i = arr.size() - 2; i >= 0; i--) {
        cost += (ll)cnt * (arr[i + 1].first - arr[i].first);
        cnt += arr[i].second;
        if (cnt >= K) {
            cost -= cnt - K;
            break;
        }
    }
    ans = min(ans, cost);
    
    // -><- 
    cost = 0;
    for (int i = 0; i < N; i++)
        cost += abs(A[i] - A[N / 2]);
    cost -= N - K;
    ans = min(ans, cost);

    cout << ans << endl;
}