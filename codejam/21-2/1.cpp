#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int query(int l, int r) {
    if (l == r)
        return l;
    int out;
    cout << "M " << l << " " << r << endl;
    cin >> out;
    // cerr << "min[" << l << ", " << r << "] = " << out << endl;
    return out;
}

void swp(int a, int b) {
    if (a == b)
        return;
    cout << "S " << a << " " << b << endl;
    int res;
    cin >> res;
}

int main() {
    int T;
    cin >> T >> N;
    for (int t = 1; t <= T; t++) {
        for (int i = 1; i <= N; i++) {
            swp(i, query(i, N));
        }
        cout << "D" << endl;
        int res;
        cin >> res;
        if (res == -1)
            return 0;
    }
}