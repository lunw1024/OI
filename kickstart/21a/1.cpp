#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;
        string s;
        cin >> s;
        for (int i = 1; i <= N / 2; i++) {
            if (s[i - 1] != s[N - i]) {
                K--;
            }
        }
        cout << "Case #" << t << ": " << abs(K) << endl;
    }
}
