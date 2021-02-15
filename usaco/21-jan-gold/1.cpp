#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const vector<char> names {'m', 'i', 'l', 'd', 'r', 'e', 'b', 's'};
const int INF = int(1e9);

int N;
string S;
vector<char> cowphabet {'a', 'b', 'c', 'f', 'g', 'h', 'j', 'k', 'n', 'o', 'p', 'q', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<int> dp;
vector<vector<int>> adj;

void preprocess() {
    map<char, int> mp;
    // make temp map
    for (int i = 0; i < cowphabet.size(); i++) {
        char ch = cowphabet[i];
        mp[ch] = i;
    }
    for (int i = 0; i < S.size() - 1; i++) {
        char a = S[i], b = S[i + 1];
        adj[mp[a]][mp[b]] += 1;
    }
}

int main() {
    cin >> S;
    if (find(names.begin(), names.end(), S[0]) != names.end())
        cowphabet = names;
    dp.resize(1 << cowphabet.size());
    N = cowphabet.size();
    adj.resize(N);
    for (int i = 0; i < N; i++)
        adj[i].resize(N);
    preprocess();
    // dp
    fill(dp.begin(), dp.end(), INF);
    dp[0] = 1;
    for (int s = 1; s < 1 << N; s++) {
        for (int i = 0; i < N; i++) {
            if (s >> i & 1) { // s - {i}
                int temp = dp[s ^ 1 << i];
                for (int j = 0; j < N; j++) {
                    if (s >> j & 1)
                        temp += adj[i][j];
                }
                dp[s] = min(dp[s], temp);
            }
        }
        // cout << dp[s] << endl;
    }
    cout << dp[(1 << N) - 1] << endl;
}
