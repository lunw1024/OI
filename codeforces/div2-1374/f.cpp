#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N;

int main() {
    cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i++)
        ans += (ll)i * (N - i + 1);
    for (int i = 1; i <= N - 1; i++) {
        int a, b;
        cin >> a >> b;
        ans -= (ll)min(a, b) * (N - max(a, b) + 1);
    }
    cout << ans << endl;
}