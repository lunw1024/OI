#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        ans += max(0, x - 10);
    }
    cout << ans << endl;
}