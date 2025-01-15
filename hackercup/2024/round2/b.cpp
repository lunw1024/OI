#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int H = 6, W = 7;
const int dX[4] = {0, 1, 0, -1};
const int dY[4] = {1, 0, -1, 0};

bool ok(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

bool check(vector<vector<char>>& board) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            for (int d = 0; d < 4; d++) {
                bool connect = true;
                int x = i, y = j;
                for (int k = 0; k < 3; k++) {
                    x += dX[d];
                    y += dY[d];
                    if (!ok(x, y) || board[i][j] != board[x][y]) {
                        connect = false;
                        break;
                    }
                }
                if (connect) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    vector<vector<char>> board(H, vector<char>(W));
    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> board[i][j];
            }
        }
        vector<int> cnt = {0, 0};
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                int player = board[i][j] == 'C';
                for (int d = 0; d < 4; d++) {
                    bool connect = true;
                    int x = i, y = j;
                    for (int k = 0; k < 3; k++) {
                        x += dX[d];
                        y += dY[d];
                        if (!ok(x, y) || board[i][j] != board[x][y]) {
                            connect = false;
                            break;
                        }
                    }
                    x = i, y = j;
                    if (connect) {
                        // cerr << "checking..." << endl;
                        // make new board
                        vector<vector<char>> b(H, vector<char>(W, '.'));
                        for (int k = 0; k < 4; k++) {
                            for (int g = x + 1; g < H; g++) {
                                b[g][y] = board[g][y];
                            }
                            x += dX[d];
                            y += dY[d];
                        }
                        // for (int ii = 0; ii < H; ii++) {
                        //     for (int jj = 0; jj < W; jj++) {
                        //         cerr << b[ii][jj];
                        //     }
                        //     cerr << endl;
                        // }
                        // check board win state
                        if (!check(b)) {
                            // cerr << (player == 0 ? "F" : "C") << " can win at " << i << " " << j << " with d=" << d << endl;
                            cnt[player]++;
                        }
                        // cerr << "checked!" << endl;
                    }
                }
            }
        }
        string ans;
        if (cnt[0] > 0 && cnt[1] > 0) {
            ans = "?";
        } else if (cnt[0] == 0 && cnt[1] > 0) {
            ans = "C";
        } else if (cnt[0] > 0 && cnt[1] == 0) {
            ans = "F";
        } else if (cnt[0] == 0 && cnt[1] == 0) {
            ans = "0";
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
