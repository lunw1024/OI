#include <atcoder/all>
#include <iostream>
using namespace atcoder;
using namespace std;

int N, X;

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x != X)
            cout << x << " ";
    }
    cout << endl;
}