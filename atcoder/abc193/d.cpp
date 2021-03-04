#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pii = pair<int, int>;

int K;
vector<int> S(10), T(10);

int score(vector<int> &cnt, int x) {
    int out = 0;
    for (int i = 1; i <= 9; i++) {
        out += i * pow_mod(10, cnt[i] + (x == i), int(1e9));
    }
    return out;
}

int main() {
    cin >> K;
    for (int i = 0; i < 5; i++) {
        char ch;
        cin >> ch;
        if (ch == '#')
            continue;
        S[ch - '0'] += 1;
    }
    for (int i = 0; i < 5; i++) {
        char ch;
        cin >> ch;
        if (ch == '#')
            continue;
        T[ch - '0'] += 1;
    }

    double ans = 0;
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            int cnta = K - S[a] - T[a];
            int cntb = K - S[b] - T[b] - (a == b);
            if (cnta <= 0 || cntb <= 0)
                continue;

            // prob
            int left = K * 9 - 8;
            double p = double(cnta) / left * cntb / (left - 1);
            if (score(S, a) > score(T, b))
                ans += p;
        }
    }
    cout << setprecision(10) << ans << endl;
}