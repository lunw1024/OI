#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N >> K;
        int counter = K, ans = 0;
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            if (a == counter) {
                counter--;
                if (counter == 0) {
                    counter = K;
                    ans++;
                }
            } else if (a == K) {
                counter = K - 1;
            } else {
                counter = K;
            }
        }
        cout << "Case #" << caseNo << ": " << ans << endl;
    }
}
