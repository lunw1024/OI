#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
using pii = pair<int, int>;

const int INF = int(1e9);
int N, M;
vector<pii> edges;
vector<int> t, n;
vector<pii> A, B;

int main() {
    int T;
    cin >> T;
    for (int caseNo = 1; caseNo <= T; caseNo++) {
        cin >> N >> M;
        edges.clear(), t.clear(), n.clear(), A.clear(), B.clear();
        t.resize(N + 1), n.resize(N + 1);
        for (int i = 2; i <= N; i++) {
            int x;
            cin >> x;
            if (x > 0) {
                t[i] = x;
                A.push_back(make_pair(t[i], i));
            } else {
                n[i] = -x;
                B.push_back(make_pair(n[i], i));
            }
        }
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            edges.push_back(make_pair(a, b));
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int pa = 0, pb = 0;
        for (int p = 1, cnt = 1; cnt < N; cnt++) {
            cerr << pa << " " << pb << " " << p << endl;
            if (pb < B.size() && B[pb].first <= cnt) {
                int b = B[pb].second;
                t[b] = n[b] == n[p] ? t[p] : t[p] + 1;
                p = b;
                pb++;
            } else {
                int a = A[pa].second;
                n[a] = t[a] == t[p] ? n[p] : N;
                p = a;
                pa++;
            }
        }
        /* for (int i = 1; i <= N; i++) {
            cerr << t[i] << " ";
        }
        cerr << endl; */
        // contrust edge weights with t[]
        cout << "Case #" << caseNo << ":";
        for (pii e : edges) {
            int a = e.first, b = e.second;
            cout << " " << max(1, abs(t[a] - t[b]));
        }
        cout << endl;
    }
}
