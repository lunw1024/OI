#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, C;
        cin >> N >> C;
        C += 1; // last
        if (C < N || C > (N + 1) * N / 2) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            continue;
        }

        C -= N;
        int m = 0;
        for (int k = N - 1; k > 0; k--) {
            if (C - k > 0)
                C -= k, m++;
            else
                break;
        }
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            arr[i] = i + 1;
        for (int i = N - 1; i >= 0; i--) {
            if (i == m) {
                reverse(arr.begin() + i, arr.begin() + i + C + 1);
            } else if (i < m) {
                reverse(arr.begin() + i, arr.end());
            }
        }
        // cerr << m << " " << C << endl;
        cout << "Case #" << t << ": ";
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}
