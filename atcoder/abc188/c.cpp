#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;
    int l = 0, argl = 0;
    for (int i = 1; i <= (1 << N - 1); i++) {
        int x;
        cin >> x;
        if (x > l) {
            l = x;
            argl = i;
        }
    }
    int r = 0, argr = 0;
    for (int i = (1 << N - 1) + 1; i <= (1 << N); i++) {
        int x;
        cin >> x;
        if (x > r) {
            r = x;
            argr = i;
        }
    }
    if (l > r)
        cout << argr << endl;
    else
        cout << argl << endl;
}