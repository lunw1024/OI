#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using ll = long long;

const int MAXN = 5000;

int main() {
    int T;
    cin >> T;
    vector<vector<double>> K(MAXN + 1, vector<double>(MAXN + 1));
    K[1][1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        for (int j = 1; j <= i; j++) {
            if (j != 1)
                K[i][j] += (j - 1) * K[i - 1][j - 1] + 1;
            if (j != i)
                K[i][j] += (i - j) * K[i - 1][j] + 1;
            K[i][j] /= i - 1;
        }
    }
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        int N;
        cin >> N;
        double ans = 0;
        for (int i = 1; i <= N; i++) {
            int a;
            cin >> a;
            ans += K[N][i] * a;
        }
        cout << "Case #" << caseNo << ": " << setprecision(6) << ans << endl;
    }
}