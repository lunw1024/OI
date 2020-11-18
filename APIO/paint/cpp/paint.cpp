#include "paint.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = (int)1e5 + 1;
int F[MAXN];

int minimumInstructions(int N, int M, int K, std::vector<int> C, std::vector<int> A, std::vector<std::vector<int>> B) {
    bool flag = true;

    if (flag) {
        fill(F, F + K, -1);
        for (int i = 0; i < M; i++) {
            for (int b : B[i]) {
                F[b] = i;
            }
        }
        for (int c : C)
            if (F[c] == -1)
                return -1;
        int p = 0, ans = 0;
        while (p < N) {
            int len = 0;
            while (p < N - 1 && F[C[p + 1]] == (F[C[p]] + 1) % M) {
                p++, len++;
            }
            p++, len++;
            if (len < M)
                return -1;
            ans += (len + M - 1) / M;
        }
        return ans;
    }
    return 0;
}
