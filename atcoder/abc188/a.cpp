#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int x, y;
    cin >> x >> y;
    cout << (abs(x - y) <= 2 ? "Yes" : "No") << endl;
}