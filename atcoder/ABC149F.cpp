#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
bool kind[16];
int n[16] = {0};
vector<pair<int, bool>> test[16];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            a--;
            test[i].push_back(make_pair(a, (bool)b));
            // cout << "(" << a << " " << b << ")" << endl;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        bool flag = true;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                for (pair<int, bool> p : test[j]) {
                    if ((bool)(i & (1 << p.first)) != p.second) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) {
            int temp = 0;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    temp++;
                }
            }
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
}