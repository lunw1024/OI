#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vi> towers(n);
    vector<int> a;
    int s = 0, c = -1;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        s += m - 1;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            towers[i].push_back(x);
            a.push_back(x);
            c++;
        }
    }
    sort(a.begin(), a.end());
    map<int, int> f;
    for (int i = 0; i < a.size(); i++) {
        f[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < towers[i].size() - 1; j++) {
            if (f[towers[i][j]] + 1 == f[towers[i][j + 1]]) {
                s--;
                c--;
            }
        }
    }
    cout << s << " " << c << endl;
}

