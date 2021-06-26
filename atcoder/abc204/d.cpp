#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    cin >> N;
    set<int> s;
    s.insert(0);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum += x;
        vector<int> cache;
        for (int y : s)
            cache.push_back(y + x);
        for (int z : cache)
            s.insert(z);
    }
    auto it = s.lower_bound(sum / 2);
    cout << max(*it, sum - *it) << endl;
}