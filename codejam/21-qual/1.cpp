#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i; j < N; j++) {
                if (v[j] == i + 1) {
                    reverse(v.begin() + i, v.begin() + j + 1);
                    ans += j - i + 1;
                    break;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
