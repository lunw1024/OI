#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int N;
ll K, ans = 0;
ll a[(int)2e5 + 1] = {0};
map<ll, int> mp;

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        a[i] = (a[i] - i + K) % K;
    }
    // init window
    for (int i = 0; i <= N; i++) {
        if (i >= K) {
            mp[a[i - K]]--;
        }
        ans += mp[a[i]];
        mp[a[i]]++;
    }
    cout << ans << endl;
}