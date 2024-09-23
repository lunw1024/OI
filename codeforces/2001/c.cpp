#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using pii = pair<int, int>;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine hashes
    }
};

int q(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int mid;
    cin >> mid;
    return mid;
}

void search_path(int a, int b, vector<int>& vis, unordered_set<pii, pair_hash>& set) {
    if (vis[a] && vis[b]) {
        return;
    }
    int mid = q(a, b);
    if (mid == a) {
        if (a > b) {
            swap(a, b);
        }
        set.insert(make_pair(a, b));
        vis[a] = true;
        vis[b] = true;
        return;
    }
    search_path(a, mid, vis, set);
    search_path(mid, b, vis, set);
} 

void solve(int n) {
    vector<int> vis(n+1);
    unordered_set<pii, pair_hash> set;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        // if (vis[i]) {
        //     continue;
        // }
        // int a = 1;
        // int mid = q(a, i);
        // while (vis[mid]) {
        //     a = mid;
        //     mid = q(a, i);
        // }
        search_path(1, i, vis, set);
    }
    cout << "!";
    for (pii e : set) {
        cout << " " << e.first << " " << e.second;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        solve(n);
    }
}
