// binary search
// prefix sum of count[i]
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> C, pre;
ifstream fin("greedy.in");
ofstream fout("greedy.out");

int main() {
    fin >> N;
    C.resize(N + 1); pre.resize(N + 1);
    for (int i = 1; i <= N; i++)
        fin >> C[i];
    int l = 1, r = N;
    while (l <= r) {
        int mid = (l + r) / 2;
        fill(pre.begin(), pre.end(), 0);
        for (int i = 1; i < mid; i++)
            pre[N - C[i]] += 1;
        for (int i = 1; i <= N; i++)
            pre[i] += pre[i - 1];
        bool flag = false;
        for (int k = 1; k < mid; k++) {
            if (pre[k] >= k)
                flag = true;
        }
        if (flag) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    fout << N - r << endl;
}