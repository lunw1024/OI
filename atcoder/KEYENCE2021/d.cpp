#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

const int pow2[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};

int popcount(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x & 1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    cout << pow2[N] - 1 << endl;
    for (int i = 1; i <= pow2[N] - 1; i++) {
        for (int j = 1; j <= pow2[N]; j++) {
            cout << (popcount(i & j) & 1 ? 'A' : 'B');
        }
        cout << endl;
    }
}
