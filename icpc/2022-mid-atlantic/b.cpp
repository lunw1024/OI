#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }
    int ansmin = int(1e9), ansmax = -int(1e9);
    for (int d = l; d <= r; d++) {
        for (int i = 1; i <= d; i++) {
            int score = 0;
            score += prefix[i] > 0;
            for (int j = i; j < n; j += d) {
                int ub = min(j + d, n);
                score += (prefix[ub] - prefix[j] > 0);
            }
            ansmin = min(ansmin, score);
            ansmax = max(ansmax, score);
        }
    }
    cout << ansmin << " " << ansmax << endl;
}
