#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N;
        vector<int> v;
        int prev;
        cin >> prev;
        for (int i = 1; i < N; i++) {
            int x;
            cin >> x;
            v.push_back(x - prev);
            prev = x;
        }
        int temp = 2, ans = 2;
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1])
                temp++;
            else
                temp = 2;
            ans = max(ans, temp);
        }
        cout << "Case #" << caseNo << ": " << ans << endl;
    }
}