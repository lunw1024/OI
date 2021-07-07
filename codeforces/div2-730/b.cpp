#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            sum += x;
        }
        sum %= N;
        cout << sum * (N - sum) << endl;
    }
}