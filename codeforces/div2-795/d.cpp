#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const ll INF = -ll(1e18);
int N;
vector<ll> a, pre, log;
vector<vector<ll>> mx, mi;

ll sum(int l, int r) {
    return pre[r] - pre[l - 1];
}

ll maxsum(int l, int r, int mid) {
    return max(mx[mid])
}

int main() {
    int T;
    cin >> T;
    log[1] = 0;
    log[2] = 1;
    for (int i = 3; i <= 200001; i++) {
        log[i] = log[i / 2] + 1;
    }
    for (int t = 0; t < T; t++) {
        cin >> N;
        a.clear();
        a.resize(N + 1);
        pre.clear();
        pre.resize(N + 1);
        mx.clear();
        mx.resize(N, vector<ll>(log[N] + 1));
        mi.clear();
        mi.resize(N, vector<ll>(log[N] + 1));
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
            mx[i][0] = pre[i];
            mi[i][0] = pre[i];
        }

        for (int j = 1; j <= log[N]; j++) {
            for (int i = 0; i + (1 << j) - 1 <= N; i++) {
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
                mi[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            }
        }


        vector<pair<ll, int>> stack;
        bool ans = true;
        for (int i = 1; i <= N; i++) {
            pre[i] = pre[i - 1] + a[i];
            while (!stack.empty() && stack.back().first <= a[i]) {
                int l = stack.size() > 1 ? stack[stack.size() - 2].second + 1 : 1;
                int r = i - 1;
                if (sum(l, r) > stack.back().first) {
                    ans = false;
                }
                stack.pop_back();
            }
            stack.push_back(make_pair(a[i], i));
        }
        while (!stack.empty()) {
            int l = stack.size() > 1 ? stack[stack.size() - 2].second + 1 : 1;
            int r = N;
            if (sum(l, r) > stack.back().first) {
                ans = false;
            }
            stack.pop_back();
        
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
}
