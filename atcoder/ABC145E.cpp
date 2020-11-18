#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, T;
int dp[3001] = {0};
pair<int, int> arr[3001];

int main() {
    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr + 1, arr + 1 + N);

    for (int i = 1; i <= N; i++) {
        int a = arr[i].first, b = arr[i].second;
        for (int j = 0; j < T; j++) {
            dp[T] = max(dp[T], dp[j] + b);
        }
        for (int j = T - 1; j > 0; j--) {
            if (j >= a) {
                dp[j] = max(dp[j], dp[j - a] + b);
            }
        }
    }
    cout << dp[T] << endl;
}