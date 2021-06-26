#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << a << endl;
    else
        cout << (3 - a - b) << endl;
}