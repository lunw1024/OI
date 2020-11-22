#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target = 0;
bool f(int v) { return v < target; }

int N, Q;

int main()
{
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    segtree<int, op, e> tree(arr);

    for (int i = 1; i <= Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            tree.set(x - 1, v);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << tree.prod(l - 1, r) << endl;
        } else {
            int l;
            cin >> l >> target;
            cout << (tree.max_right<f>(l - 1) + 1) << endl;
        }
    }
}
