// http://usaco.org/index.php?page=viewproblem2&cpid=1091
// sum of all traveled positions for each starting pos in one go is 4 * 10^5
// all cycles are simple
// T = M / K = whole iterations
// Since sum of all traveled positions <= 10^5
// can do each cycle separately, if L <= T, all positions are traveled.
// if L < T, do sliding window, complexity = O(K + N)
// For extra R swaps, preprocess for each set, the earliest time reaching some positions
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
int N, K, R;
ll M, T;
vector<pii> swaps;
vector<set<pii>> sets; // set s_i, the traveled positions for node i in one iteration
vector<int> cnts, arr, ans;
vector<bool> vis;
int unique_e = 0;

void add_set(int x) {
    for (pii e : sets[x]) {
        cnts[e.second] += 1;
        if (cnts[e.second] == 1)
            unique_e += 1;
    }
}

void remove_set(int x) {
    for (pii e : sets[x]) {
        cnts[e.second] -= 1;
        if (cnts[e.second] == 0)
            unique_e -= 1;
    }
}

void preprocess() {
    // sets and arr
    for (int i = 0; i < N; i++)
        arr[i] = i;
    for (int i = 0; i < N; i++)
        sets[arr[i]].insert(make_pair(0, i)); // initial pos
    for (int i = 1; i <= K; i++) {
        pii e = swaps[i - 1];
        swap(arr[e.first], arr[e.second]);
        sets[arr[e.first]].insert(make_pair(i, e.first));
        sets[arr[e.second]].insert(make_pair(i, e.second));
    // multiple entry is safe here, since cnts[] will be updated properly
    }
}

void solve(vector<int>& cycle) {
    int L = cycle.size();
    // cout << "solving a cycle of len " << L << endl;
    // for (int i : cycle)
        // cout << i << " ";
    // cout << "}" << endl;
    if (L <= T) {
        for (int x : cycle)
            add_set(x);
        for (int x : cycle)
            ans[x] = unique_e;
        for (int x : cycle)
            remove_set(x);
        return;
    }
    // init window
    for (int i = 0; i < T; i++)
        add_set(cycle[i]);
    for (int i = 0; i < L; i++) {
        // do extra R swaps on set[cycle[i + T]]
        for (pii e : sets[cycle[(i + T) % L]]) {
            if (e.first > R)
                break;
            cnts[e.second] += 1;
            if (cnts[e.second] == 1)
                unique_e += 1;
        }
        ans[cycle[i]] = unique_e; // record answer
        // undo R extra swaps
        for (pii e : sets[cycle[(i + T) % L]]) {
            if (e.first > R)
                break;
            cnts[e.second] -= 1;
            if (cnts[e.second] == 0)
                unique_e -= 1;
        }
        // update window
        remove_set(cycle[i]);
        add_set(cycle[(i + T) % L]);
    }
    // clear window
    for (int i = 0; i < T; i++)
        remove_set(cycle[i]);
    // assert(unique_e == 0);
}

int main() {
    cin >> N >> K >> M;
    T = M / K;
    R = M - T * K;
    arr.resize(N); cnts.resize(N); sets.resize(N); vis.resize(N); ans.resize(N);
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        swaps.push_back(make_pair(a - 1, b - 1));
    }
    preprocess();
    // cout << "arr: ";
    // for (int i : arr)
        // cout << i << " ";
    // cout << endl;
    // for (int i = 0; i < N; i++) {
        // for (pii e : sets[i])
            // cout << "(" << e.first << ", " << e.second << ") ";
        // cout << endl;
    // }
    // do each cycle
    for (int i = 0; i < N; i++) {
        if (vis[i])
            continue;
        vector<int> cycle;
        cycle.push_back(i);
        vis[i] = true;
        for (int p = arr[i]; p != i; p = arr[p]) {
            cycle.push_back(p);
            vis[p] = true;
        }
        reverse(cycle.begin(), cycle.end());
        solve(cycle);
    }
    for (int i = 0; i < N; i++)
        cout << ans[i] << endl;
}

