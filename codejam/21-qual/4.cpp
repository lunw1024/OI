#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, Q;
vector<int> arr;

int query(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
    int ret;
    cin >> ret;
    return ret;
}

void solve(int l, int r) {
    // cerr << "solving " << l << " " << r << endl;
    if (r - l + 1 <= 2)
        return;
    int x = arr[l], y = arr[l + 1];
    vector<int> a, b, c;
    for (int i = l + 2; i <= r; i++) {
        int z = arr[i];
        int med = query(x, y, z);
        if (med == x)
            a.push_back(z);
        else if (med == z)
            b.push_back(z);
        else if (med == y)
            c.push_back(z);
    }
    int A = a.size(), B = b.size(), C = c.size();
    // cerr << "x = " << x << ", y = " << y << ", A = " << A << ", B = " << B << ", C = " << C << endl;
    copy(a.begin(), a.end(), arr.begin() + l);
    arr[l + A] = x;
    copy(b.begin(), b.end(), arr.begin() + l + A + 1);
    arr[l + A + 1 + B] = y;
    copy(c.begin(), c.end(), arr.begin() + l + A + 1 + B + 1);

    /* cerr << "after copy: ";
    for (int i = 1; i <= N; i++)
        cerr << arr[i] << " ";
    cerr << endl; */

    solve(l, l + A - 1);
    solve(l + A + 1, l + A + B);
    solve(l + A + B + 2, l + A + B + 1 + C);

    /* cerr << "coming back to " << l << " " << r << endl;
    for (int i = 1; i <= N; i++)
        cerr << arr[i] << " ";
    cerr << endl; */

    if (A > 1 && query(arr[l], arr[l + 1], x) == arr[l])
        reverse(arr.begin() + l, arr.begin() + l + A);
    if (B > 1 && query(arr[l + A + 1], arr[l + A + 2], y) == arr[l + A + 1])
        reverse(arr.begin() + l + A + 1, arr.begin() + l + A + 1 + B);
    if (C > 1 && query(arr[l + A + B + 2], arr[l + A + B + 3], y) == arr[l + A + B + 3])
        reverse(arr.begin() + l + A + B + 2, arr.begin() + l + A + B + 2 + C);
    
    /* cerr << "after reverse: ";
    for (int i = 1; i <= N; i++)
        cerr << arr[i] << " ";
    cerr << endl; */
}

int main() {
    int T;
    cin >> T >> N >> Q;
    arr.resize(N + 1);
    for (int t = 1; t <= T; t++) {
        for (int i = 1; i <= N; i++) {
            arr[i] = i;
        }
        solve(1, N);
        for (int i = 1; i <= N; i++)
            cout << arr[i] << " ";
        cout << endl;
        // cerr << "case ended" << endl;
        int result;
        cin >> result;
        if (result != 1)
            return 1;
    }
}
