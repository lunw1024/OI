#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int MOD = (int)1e9;
int W, H, L, U, R, D;
double logfact[(int)2e5] = {0};

void preprocess() {
    logfact[0] = 0;
    for (int i = 1; i < (int)2e5; i++) {
        logfact[i] = logfact[i - 1] + log2(i);
    }
}

int main() {
    int T;
    cin >> T;
    preprocess();
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> W >> H >> L >> U >> R >> D;
        double ans = 0;
        // upper right
        int n = R + U - 2;
        for (int m = 0; R < W && m <= U - 2; m++) {
            double p = logfact[n] - logfact[m] - logfact[n - m] - n;
            ans += pow(2, p);
        }
        // bottom left
        n = D + L - 2;
        for (int m = 0; D < H && m <= L - 2; m++) {
            double p = logfact[n] - logfact[m] - logfact[n - m] - n;
            ans += pow(2, p);
        }
        cout << "Case #" << caseNo << ": " << ans << endl;
    }
}

