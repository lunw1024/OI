#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


struct UnionFindSet{
    int n;
    vector<int> fa;
    UnionFindSet(int n) {
        this->n = n;
        fa.resize(n);
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        fa[x] = y;
    }
};

int T, N;
vector<vector<int>> edges, f; // f[i]: nodes of color i
vector<int> h, fa;

void calc_height(int u, int prev) {
    fa[u] = prev;
    h[u] = h[prev] + 1;
    for (int v : edges[u]) {
        if (v == prev)
            continue;
        calc_height(v, u);
    }
}


ifstream fin("chainblock_validation_input.txt");
ofstream fout("out.txt");

int main() {
    fin >> T;
    for (int t = 1; t <= T; t++) {
        fin >> N;
        UnionFindSet s(N + 1); // next possible node
        h.clear();
        h.resize(N + 1);
        f.clear();
        f.resize(N + 1);
        fa.clear();
        fa.resize(N + 1);
        edges.clear();
        edges.resize(N + 1);

        for (int i = 0; i < N - 1; i++) {
            int a, b;
            fin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        calc_height(1, 1);

        for (int i = 1; i <= N; i++) {
            int c;
            fin >> c;
            f[c].push_back(i);
        }

        // solve
        int ans = N - 1;
        for (int c = 1; c <= N; c++) {
            // cout << "c: " << c << endl;
            priority_queue<pii> q;
            for (int u : f[c]) {
                int v = s.find(u);
                q.push(make_pair(h[v], v));
            }
            while (q.size() > 1) {
                int u = q.top().second;
                q.pop();
                if (u == q.top().second) // remove replica
                    continue;
                
                if (fa[u] != u && s.find(u) == u) {
                    ans--;
                    s.merge(u, fa[u]);
                    int v = s.find(u); // next possible node
                    q.push(make_pair(h[v], v));
                }
            }
        }

        fout << "Case #" << t << ": " << ans << endl;
    }
}