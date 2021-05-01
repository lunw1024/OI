#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = int(1e9);
int N, K;

void update(vector<int>& ans, int x) {
    if (x > ans[1])
        ans[1] = x;
    if (ans[1] > ans[0])
        swap(ans[0], ans[1]);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(2);
        for (int i = 0; i <= N; i++) {
            if (i == 0) {
                update(ans, arr[0] - 1);
            } else if (i == N) {
                update(ans, K - arr[N - 1]);
            } else {
                update(ans, (arr[i] - arr[i - 1]) / 2);
            }
        }
        int ans1 = ans[0] + ans[1];
        int ans2 = 0;
        for (int i = 0; i < N - 1; i++) {
            ans2 = max(ans2, arr[i + 1] - arr[i] - 1);
        }
        double answer = 1.0 * max(ans1, ans2) / K;
        cout << "Case #" << t << ": " << answer << endl;
    }
}