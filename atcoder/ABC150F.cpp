#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAXN = (int)2e5;
int N;
bool A[30][MAXN], B[30][MAXN];
int ans[30][MAXN];

vector<int> prefix_function(int idx) {
    vector<int> pi(N);
    for (int i = 1; i < N; i++) {
        int j = pi[i - 1];
        while (j > 0 && A[idx][j] != A[idx][i])
            j = pi[j - 1];
        if (A[idx][i] == A[idx][j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void kmp(int idx, vector<int>& prefix, bool reverse = false) {
    int match = 0;
    for (int i = 0; i < 2 * N - 1; i++) {
        while (match > 0 && A[idx][match] != reverse ^ B[idx][i % N])
            match = prefix[match - 1];
        if (A[idx][match] == reverse ^ B[idx][i % N])
            match++;
        if (match == N) {
            ans[idx][i - N + 1] = reverse;
            match = prefix[match - 1]; 
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        for (int j = 0; a > 0; a >>= 1, j++)
            A[j][i] = a % 2;
    }
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        for (int j = 0; b > 0; b >>= 1, j++)
            B[j][i] = b % 2;
    }

    fill(&ans[0][0], &ans[29][MAXN], -1);
    for (int i = 0; i < 30; i++) {
        vector<int> prefix = prefix_function(i);
        kmp(i, prefix, false);
        kmp(i, prefix, true);
    }

    for (int i = N; i > 0; i--) {
        bool flag = ans[0][i % N] >= 0;
        for (int j = 1; j < 30; j++) {
            if (ans[j][i % N] < 0)
                flag = false;
        }
        if (flag) {
            int x = 0;
            for (int j = 29; j >= 0; j--) {
                x |= ans[j][i % N];
                if (j > 0)
                    x <<= 1;
            }
            cout << (N - i) << " " << x << endl;
        }
    }
}