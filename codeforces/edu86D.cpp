#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int N, K, ans = 0;
int cnt[(int)2e5 + 1] = {0}, suf[(int)2e5 + 2] = {0};
int k[(int)2e5 + 2] = {0}, a[(int)2e5 + 1] = {0};
vector<int> v[(int)2e5 + 1];

int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a + 1, a + 1 + N, greater<int>());
    for (int i = 1; i <= K; i++) {
        cin >> k[i];
    }
    for (int i = K; i >= 1; i--) {
        suf[i] = suf[i + 1] + cnt[i];
    }

    for (int i = 1; i <= K; i++) {
        ans = max(ans, (int)ceil((double)suf[i] / k[i]));
    }

    int p = 0;
    for (int i = 1; i <= N; i++) {
        if (v[p].size() < k[a[i]]) {
            v[p].push_back(a[i]);
        } else {
            p = (p + 1) % ans;
            i--;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < ans; i++) {
        cout << v[i].size() << " ";
        for (int j : v[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}