#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;

int main() {
    int N;
    cin >> N;
    char aa, ab, ba, bb;
    cin >> aa >> ab >> ba >> bb;
    mint ans = 0;
    if (N <= 3) {
        ans = 1;
    } else if (ab == 'A') {
        if (aa == 'A')
            ans = 1;
        else if (ba == 'B') {
            ans = 1;
            for (int i = 0; i < N - 2; i++)
                ans *= 2;
        } else {
            mint a = 1, b = 1;
            for (int i = 0; i < N - 3; i++) {
                b += a;
                swap(a, b);
            }
            ans = a;
        }
    } else {
        if (bb == 'B')
            ans = 1;
        else if (ba == 'A') {
            ans = 1;
            for (int i = 0; i < N - 3; i++)
                ans *= 2;
        } else {
            mint a = 1, b = 1;
            for (int i = 0; i < N - 3; i++) {
                b += a;
                swap(a, b);
            }
            ans = a;
        }
    }
    cout << ans.val() << endl;
}