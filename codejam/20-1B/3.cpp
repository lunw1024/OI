// operation is take a consecutive subarray and put to the top. The bottom part is unchanged
// try to examine the number of consecutive regions with same rank
// Necessary: reduce the number of regions down to R
// simpler question: sort using the operation. requires <= n, calculated by repeatedly traveling the array.
// observation 1: connected should not be separated
// observation 2: one operation can connect at most 2 pairs
// So the min ops has a lower bound of R(C-1) / 2
// Then, natually we try to construct a solution
// Key observation: the adj pairs is either equal or +1 (mod R)
// So we can always reduce the number of regions by 2
// QED

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int R, C;
vector<int> arr;

void operate(int l, int r) {
    cout << l - 1 << " " << r - l << endl;
    vector<int> A(arr.begin() + 1, arr.begin() + l);
    vector<int> B(arr.begin() + l, arr.begin() + r);
    copy(B.begin(), B.end(), arr.begin() + 1);
    copy(A.begin(), A.end(), arr.begin() + 1 + B.size());
    // cerr << "new arr: ";
    // for (int i : arr) {
    //     cerr << i << " ";
    // }
    // cerr << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> R >> C;
        int N = R * C;
        arr = {0};
        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= R; j++) {
                arr.push_back(j);
            }
        }
        cout << "Case #" << t << ": " << (R * (C - 1) + 1) / 2 << endl;
        for (int i = 1; i <= (R * (C - 1) + 1) / 2; i++) {
            int a = arr[1], b = 0;
            // cerr << "a = " << a << endl;
            int r = 1;
            while (arr[r] == a)
                r++;
            for (; r <= N && b == 0; r++) { // find the next a
                if (arr[r] == a) {
                    for (; r <= N - 1; r++) { // find b
                        if (arr[r + 1] != a) {
                            b = arr[r + 1];
                            // cerr << "find b = " << b << " at " << r << endl;
                            break;
                        }
                    }
                }
            }
            if (b == 0) {
                int l = 1;
                r = N;
                while (l <= N and arr[l] == arr[1])
                    l++;
                while (r >= 1 && arr[r] == arr[1])
                    r--;
                r++;
                operate(l, r);
                continue;
            }
            // find the prev b
            int l = r;
            for (; l >= 2; l--) {
                if (arr[l - 1] == b)
                    break;
            }
            operate(l, r);
        }
    }
}