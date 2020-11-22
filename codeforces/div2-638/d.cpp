#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int N;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N;
        int ans = (int)log2(N), prev = 1;
        N -= 1 * ans + 1;
        cout << ans << endl;
        for (int i = 1; i <= ans; i++) {
            int x = min(prev, N / (ans - i + 1));
            N -= x * (ans - i + 1);
            prev += x;
            cout << x << " ";
        }
        cout << endl;
    }
    // system("pause"); 
}