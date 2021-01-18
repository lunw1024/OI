#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

int H, W, K;


int main() {
    cin >> H >> W >> K;
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < K; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        grid[x - 1][y - 1] = c;
    }
    vector<vector<mint>> dp(H, vector<mint>(W));
    dp[0][0] = 1;
    mint inv3 = mint(3).inv();
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            mint w = dp[i][j];
            if (grid[i][j] == 0)
                w *= inv3;
            if (grid[i][j] == 'R' || grid[i][j] == 0)
                if (j + 1 < W)
                    dp[i][j + 1] += w;
            if (grid[i][j] == 'D' || grid[i][j] == 0)
                if (i + 1 < H)
                    dp[i + 1][j] += w;
            if (grid[i][j] == 'X' || grid[i][j] == 0) {
                if (j + 1 < W)
                    dp[i][j + 1] += w;
                if (i + 1 < H)
                    dp[i + 1][j] += w;
            }
        }
    }
    mint ans = dp[H - 1][W - 1] * pow_mod(3, H * W - K, 998244353);
    cout << ans.val() << endl;
}