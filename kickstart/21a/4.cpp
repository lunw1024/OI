#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using Edge = pair<int, pii>;

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


int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N));
        vector<Edge> edges;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> B[i][j];
        for (int i = 0; i < N; i++) {
            int trash;
            cin >> trash;
        }
        for (int i = 0; i < N; i++) {
            int trash;
            cin >> trash;
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] == -1) {
                    edges.push_back(make_pair(B[i][j], make_pair(i, j + N)));
                    ans += B[i][j];
                }
            }
        }

        sort(edges.begin(), edges.end(), greater<Edge>());

        // kruskal
        UnionFindSet s(2 * N);
        for (Edge e : edges) {
            int w = e.first, x = e.second.first, y = e.second.second;
            if (s.find(x) != s.find(y)) {
                ans -= w;
                s.merge(x, y);
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}