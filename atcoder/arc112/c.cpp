// for each subtree, see 1. if the move order will change (odd size) and 2. the coins each player will get
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<int> parent, sz;
vector<vector<int>> children;


int dfs(int u) {
    sz[u] = 1;
    vector<int> even, odd;
    for (int v : children[u]) {
        int diff = dfs(v);
        if (sz[v] % 2 == 1)
            odd.push_back(diff);
        else
            even.push_back(diff);
        sz[u] += sz[v];
    }
    int res = 1, p = 0;
    bool my_turn = true;
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    for (; p < even.size(); p++) {
        if (even[p] > 0)
            break;
        res += (my_turn ? 1 : -1) * even[p];
    }
    for (int diff : odd) {
        res += (my_turn ? 1 : -1) * diff;
        my_turn = !my_turn;
    }
    for (; p < even.size(); p++)
        res += (my_turn ? 1 : -1) * even[p];
    // cout << "dfs(" << u + 1 << ") = " << res << endl;
    return res;
}

int main() {
    cin >> N;
    parent.resize(N); sz.resize(N); children.resize(N);
    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        children[parent[i]].push_back(i);
    }
    cout << (dfs(0) + sz[0]) / 2 << endl;
}
