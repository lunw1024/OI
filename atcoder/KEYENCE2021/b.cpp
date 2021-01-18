#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
using ll = long long;

int N, K;

int main() {
    cin >> N >> K;
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int lim = K, ans = 0;
    for (int i = 0; i < N; i++) {
        lim = min(lim, cnt[i]);
        ans += lim;
    }
    cout << ans << endl;
}