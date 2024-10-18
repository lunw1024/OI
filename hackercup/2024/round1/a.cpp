#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int task = 1; task <= T; task++) {
        int N;
        cin >> N;
        double lb = 0, ub = 1e6;
        for (int i = 1; i <= N; i++) {
            double a, b;
            cin >> a >> b;
            lb = max(lb, i / b);
            ub = min(ub, i / a);
            // cerr << lb << ", " << ub << endl;
        }
        const double eps = 1e-7;
        if (ub - lb > -eps) {
            cout << "Case #" << task << ": " << lb << endl;
        } else {
            cout << "Case #" << task << ": " << -1 << endl;
        }
    }
}
