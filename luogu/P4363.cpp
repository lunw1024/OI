#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = (int)1e9;
int N, M;
int dp[1<<21];
int board[10][10][2];

bool legal(int state) {
    int zeros = 0, ones = 0;
    while (state > 0) {
        if (state & 1)
            ones++;
        else
            zeros++;
        state >>= 1;
    }
    return zeros <= M && ones == N;
}

bool turn(int state) {
    bool out = true;
    int zeros = 0;
    while (state > 0) {
        if (state & 1)
            out ^= zeros & 1;
        else
            zeros++;
        state >>= 1;
    }
    return out;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j][1];

    // init dp
    for (int state = 0; state < (1<<N+M); state++)
        if (legal(state)) {
            dp[state] = turn(state) ? -INF : INF;
        }
    int initstate = 0;
    for (int i = 0; i < N; i++)
        initstate += 1 << i;
    dp[initstate] = 0;

    // dp
    for (int state = 0; state < (1<<N+M); state++) {
        if (!legal(state))
            continue;
        int ones = 0, zeros = 0;
        for (int i = 1; i <= state; i <<= 1) {
            if (i & state)
                ones++;
            else
                zeros++;
            if (((i & state) > 0) && (((i<<1) & state) == 0)) {
                int nstate = state + i;
                if (!legal(nstate))
                    continue;
                // cout << "from " << state << " (" << dp[state] << ") ";
                if (turn(state)) {
                    dp[nstate] = min(dp[nstate], dp[state] + board[N - ones][zeros][0]);
                    // cout << "update " << nstate << " to " << dp[state] + board[N - ones][zeros][0] << endl;
                    // cout << dp[nstate] << endl;
                } else {
                    dp[nstate] = max(dp[nstate], dp[state] - board[N - ones][zeros][1]);
                    // cout << "update " << nstate << " to " << dp[state] - board[N - ones][zeros][1] << endl;
                    // cout << dp[nstate] << endl;
                }
            }
        }
    }
    int finalstate = 0;
    for (int i = M; i < M + N; i++)
        finalstate += 1 << i;
    cout << dp[finalstate] << endl;
}