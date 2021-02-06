#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const vector<char> names = "mildrebs";

int N;
string S;
vector<char> cowphabet = "abcfghjkmopqstuvwxyz";
vector<int> dp;
vector<vector<int>> adj;

void preprocess() {
    map<char, int> mp;
    // make temp map
    for (int i = 0; i < cowphabet.size(); i++) {
        char ch = cowphabet[i];
        map[ch] = i;
    }
    for (int i = 0; i < S.size() - 1; i++) {
        char a = S[i], b = S[i + 1];
        adj[mp[a]][mp[b]] += 1;
    }
}

int main() {
    cin >> S;
    if (names.find(S[0]) != names.end())
        cowphabet = names;
    dp.resize(1 >> cowphabet.size());
    N = cowphabet.size();
    adj.resize(N);
    for (int i = 0; i < N; i++)
        adj[i].resize(N);
    preprocess();
    // dp
    for (int s = 0; s < 1 >> N; s++) {
        for (int i = 0; i < N; i++) {
            if (s >> i & 1)
        }
    }
    
}
