#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    int m, n, k, s;
    cin >> m >> n >> k >> s;
    vector<ll> upper(m), lower(n);
    for (int i = 0; i < m; i++) {
        double x;
        cin >> x;
        upper[i] = static_cast<ll>(round(x * 1000));
    }
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        lower[i] = static_cast<ll>(round(x * 1000));
    }
    
}
