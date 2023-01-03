#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    int x = 0, y = 0;
    string s;
    cin >> s;
    for (char ch : s) {
        if (ch == '1') {
            x += 1;
        } else {
            y += 1;
        }
    }
    for (int i = 1 << x; i <= (1 << N) - (1 << y) + 1; i++) {
        cout << i << " ";
    }
    cout << endl;
}
