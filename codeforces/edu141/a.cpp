#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        swap(a[1], a[N - 1]);
        if (a[0] != a[1]) {
            cout << "YES" << endl;
            for (int i : a) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
