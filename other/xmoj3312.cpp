#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int BASE1 = (int)1e9 + 7, BASE2 = (int)1e9 + 9;
int N;
ull A[50][50], B[50][50];
ull pow1[51], pow2[51];
set<ull> st;

bool check(int k) {
    st.clear();
    // hash A
    for (int i = 0; i < N - k + 1; i++) {
        for (int j = 0; j < N - k + 1; j++) {
            ull hash = 0;
            for (int a = i; a < i + k; a++) {
                for (int b = j; b < j + k; b++) {
                    hash += A[a][b] * pow1[a - i] * pow2[b - j];
                }
            }
            st.insert(hash);
        }
    }
    for (int i = 0; i < N - k + 1; i++) {
        for (int j = 0; j < N - k + 1; j++) {
            ull hash = 0;
            for (int a = i; a < i + k; a++) {
                for (int b = j; b < j + k; b++) {
                    hash += B[a][b] * pow1[a - i] * pow2[b - j];
                }
            }
            if (st.count(hash) > 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] += 1ull << 31;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
            B[i][j] += 1ull << 31;
        }
    }
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow1[i] = pow1[i - 1] * BASE1;
        pow2[i] = pow2[i - 1] * BASE2;
    }

    int l = 1, r = N;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r << endl;
}