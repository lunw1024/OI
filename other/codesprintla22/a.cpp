#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, p, x, y;
    cin >> n >> p >> x >> y;
    cout << (p * x + (p / (n - 1)) * y) << endl;
}
