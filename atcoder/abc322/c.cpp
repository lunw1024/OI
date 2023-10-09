#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for(auto& i : a) cin >> i;
    int j = 0;
    for(int i = 1; i <= n; ++i) {
        while(a[j] < i) {
            ++j;
        }
        cout << a[j] - i << '\n';
    }
}