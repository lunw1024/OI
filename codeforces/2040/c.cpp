#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        ll k;
        cin >> n >> k;
        k--;
        deque<int> ans;
        ans.push_back(n);
        for (int i = n - 1; i >= 1; i--) {
            if (k % 2) {
                ans.push_back(i);
            } else {
                ans.push_front(i);
            }
            k /= 2;
        }
        if (k > 0) {
            cout << -1 << endl;
        } else {
            for (int x : ans) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}

