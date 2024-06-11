// essentially a brute force search problem
// we know that some segment must contain the max element of the arr, so the final m must be a multiple of max.
// also, we have k segments, so m is no greater than max * n / k.
// then, we can use n queries to find the max, then use the rest of the queries to brute force every m.
// there are n / k possible candidates, and each trial takes k queries, so we can finish the search with <= n queries.

#include <iostream>
#include <vector>
using namespace std;


int ask(int l, int x) {
    cout << "? " << l << " " << x << endl;
    int out;
    cin >> out;
    if (out == -1) {
        exit(0);
    }
    return out;
}

void solve() {
    int n, k;
    cin >> n >> k;
    // find max
    int m = n;
    while (ask(1, m * n) != n) {
        m--;
    }
    // brute force through all possible solutions
    // m, 2m, 3m, ..., till we're done
    for (int i = 1; i <= n / k; i++) {
        // cout << "testing " << i * m << endl;
        int p = 0;
        int cnt = 0;
        while (p < n && cnt < k) {
            p = ask(p + 1, i * m);
            if (p == n + 1) {
                // cerr << "ohno" << endl;
                break;
            }
            cnt++;
        }
        if (p == n && cnt == k) {
            cout << "! " << i * m << endl;
            int result;
            cin >> result;
            if (result == 1) {
                return;
            } else {
                exit(0);
            }
        }
    }
    cout << "! " << -1 << endl;
    int result;
    cin >> result;
    if (result == 1) {
        return;
    } else {
        exit(0);
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}
