#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int N, K, cnt = 0;
bool exist[101] = {0};
int v[101] = {0};

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N >> K;
        vector<int> ans, arr;
        cnt = 0;
        fill(exist + 1, exist + 1 + N, false);
        for (int i = 1; i <= N; i++) {
            cin >> v[i];
        }
        for (int i = 1; i <= N; i++) {
            if (!exist[v[i]]) {
                cnt++;
                arr.push_back(v[i]);
            }
            exist[v[i]] = true;
        }

        if (cnt > K) {
            cout << "-1" << endl;
            continue;
        }

        while (arr.size() < K) {
            arr.push_back(v[1]);
        }

        for (int i = 0, p = 1; p <= N; i = (i + 1) % K) {
            if (arr[i] == v[p])
                p++;
            ans.push_back(arr[i]);
        }
        cout << ans.size() << endl;
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    // system("pause");
}