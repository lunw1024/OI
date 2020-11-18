#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = (int)2e5 + 1;
int N, A[MAXN];
vector<int> edges[MAXN];
priority_queue<int> heaps[MAXN];

void merge(int h1, int h2) {
    if (heaps[h1].size() < heaps[h2].size())
        swap(heaps[h1], heaps[h2]);
    vector<int> v(heaps[h2].size());
    while (!heaps[h2].empty()) {
        v.push_back(max(heaps[h1].top(), heaps[h2].top()));
        heaps[h1].pop();
        heaps[h2].pop();
    }
    for (int i : v)
        heaps[h1].push(i);
}

void dfs(int u) {
    for (int v : edges[u]) {
        dfs(v);
        merge(u, v);
    }
    heaps[u].push(A[u]);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 2; i <= N; i++) {
        int fa;
        cin >> fa;
        edges[fa].push_back(i);
    }
    
}