// dp[i, k]: first i intervals, k removed
// problem: how to account the overlap
// 1. filter the useless intervals
// 2. find for each interval, what's the leftmost 

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N, K;
vector<pii> intervals, arr; // (l, r)
ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

int main() {
    fin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll l, r;
        fin >> l >> r;
        intervals.push_back(make_pair(l, r));
    }
    sort(intervals.begin(), intervals.end());
    // filter
    for (int i = 0, maxr = 0; i < intervals.size(); i++) {
        pii e = intervals[i];
        if (maxr < e.second)
            arr.push_back(e);
        maxr = max(ll(maxr), e.second);
    }
    int Np = arr.size();
    // dp
    vector<vector<ll>> dp(Np, vector<ll>(K + 1));
    for (int i = 0, p = 0; i < Np; i++) {
        ll l = arr[i].first, r = arr[i].second;
        while (arr[p].second < l)
            p++;
        for (int k = 0; k <= K; k++) {
            if (k > i)
                continue;
            if (k == i)
                dp[i][k] = max(dp[i][k], r - l);
            if (p < i)
                dp[i][k] = max(dp[i][k], dp[p][max(0, k - (i - p - 1))] + r - arr[p].second);
            if (p >= 1)
                dp[i][k] = max(dp[i][k], dp[p - 1][max(0, k - (i - p))] + r - l);
        }
    }
    ll ans = 0;
    for (int i = 0; i < Np; i++) {
        ans = max(ans, dp[i][max(0, K - (N - Np) - (Np - i - 1))]);
    }
    if (K == N)
        ans = 0;
    fout << ans << endl;
}