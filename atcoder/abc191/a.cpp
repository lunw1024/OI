#include <atcoder/all>
#include <iostream>
using namespace atcoder;
using namespace std;


int main() {
    int V, T, S, D;
    cin >> V >> T >> S >> D;
    T *= V, S *= V;
    cout << (T <= D && D <= S ? "No" : "Yes") << endl;
}