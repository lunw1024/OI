#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, K;

int query(vector<int> v) {
    cout << "? ";
    for (int i : v) {
        cout << i + 1 << " ";
    }
    cout << endl;
    int out = 0;
    cin >> out;
    return out;
}

int main() {
    cin >> N >> K;
    if (N % K % (2*N % K) != 0) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0;;) {
        vector<int> v(K);
        for (int j = i; j < i + K; j++) {
            v[j - i] = j % N;
        }
        ans ^= query(v);
        i = (i + K) % N;
        if (i == 0)
            break;
    }
    cout << "! " << ans << endl;
}
