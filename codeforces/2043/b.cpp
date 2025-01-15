#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

ll fact(ll x) {
    if (x == 0) {
        return 1;
    }
    return x * fact(x - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll n, d;
        cin >> n >> d;
        vi ans;
        ans.push_back(1);
        if (n >= 3 || fact(n) * d % 3 == 0) {
            ans.push_back(3);
        }
        if (d % 5 == 0) {
            ans.push_back(5);
        }
        if (n >= 3 || d == 7) {
            ans.push_back(7);
        }
        if (n >= 6 || fact(n) * d % 9 == 0) {
            ans.push_back(9);
        }
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
}

