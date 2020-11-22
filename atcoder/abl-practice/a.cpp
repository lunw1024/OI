// https://atcoder.jp/contests/practice2/tasks

#include <atcoder/dsu>
#include <iostream>
using namespace std;
using namespace atcoder;

int N, Q;

int main() {
    cin >> N >> Q;
    dsu d(N);
    for (int i = 1; i <= Q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 0) {
            d.merge(u, v);
        } else {
            cout << d.same(u, v) << endl;
        }
    }
}