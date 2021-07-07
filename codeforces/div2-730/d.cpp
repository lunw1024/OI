// z ^ x = y => z = x ^ y
// z 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;

bool query(int x) {
    cout << x << endl;
    int r;
    cin >> r;
    return r == 1;
}

int kor(int a, int b) {
    if (a > b)
        swap(a, b);
    int out = 0, base = 1;
    while (a > 0) {
        out += base * ((a % K + b % K) % K);
        a /= K, b /= K;
        base *= K;
    }
    out += b * base;
    return out;
}

int inv(int x) {
    int out = 0, base = 1;
    while (x > 0) {
        out += base * ((K - x % K) % K);
        x /= K;
        base *= K;
    }
    return out;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        int a = 0;
        for (int i = 0; i < N; i++) {
            int b = 0;
            if (i % 2 == 1) {
                b = kor(inv(i), a);
            } else {
                b = kor(i, a);
            }
            if (query(b))
                break;
            a = kor(b, inv(a));
        }
    }
}