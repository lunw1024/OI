#include <iostream>
#include <algorithm>
#include <vector>
#include <atcoder/lazysegtree>
using namespace std;
using namespace atcoder;
using ll = long long;
using pii = pair<int, int>;

int N;

struct node {
    int pre;
    int suf;
    int max0, max1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);;
}
