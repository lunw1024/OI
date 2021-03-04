#include <iostream>
#include <algorithm>
#include <vector>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    double a, b;
    cin >> a >> b;
    cout << 100 * (a - b) / a << endl;
}