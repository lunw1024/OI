#include <atcoder/all>
#include <iostream>
using namespace atcoder;
using namespace std;

int H, W;
vector<vector<bool>> S(11, vector<bool>(11));

int main() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            char ch;
            cin >> ch;
            if (ch == '#')
                S[i][j] = true;
        }
    }
    int ans = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (i > 1)
                ans += !(j > 1 && (S[i][j - 1] ^ S[i - 1][j - 1])) * (S[i][j] ^ S[i - 1][j]);
            if (j > 1)
                ans += !(i > 1 && (S[i - 1][j] ^ S[i - 1][j - 1])) * (S[i][j] ^ S[i][j - 1]);
        }
    }
    cout << ans << endl;
}