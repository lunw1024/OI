#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N, M, G, R;
int A[(int)1e4], dist[(int)1e4][1000], ans = (int)1e9;
deque<P> q;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) 
        cin >> A[i];
    cin >> G >> R;
    sort(A, A + M);
    fill(&dist[0][0], &dist[M - 1][1000], -1);
    q.push_back(make_pair(0, 0));
    dist[0][0] = 0;
    
    while (!q.empty()) {
        int pos = q.front().first, t = q.front().second;
        q.pop_front();

        if (A[M - 1] - A[pos] <= G - t) {
            ans = min(ans, dist[pos][t] * (G + R) + t + A[M - 1] - A[pos]);
        }

        for (int i : {-1, 1}) {
            if (pos+i < 0 || pos+i >= M)
                continue;
            int nt = t - i*A[pos] + i*A[pos+i];
            if (nt <= G && dist[pos+i][(nt) % G] == -1) {
                if (nt == G) {
                    dist[pos+i][0] = dist[pos][t] + 1;
                    q.push_back(make_pair(pos+i, 0));
                } else {
                    dist[pos+i][nt] = dist[pos][t];
                    q.push_front(make_pair(pos+i, nt));
                }
            }
        }
    }
    cout << (ans == (int)1e9 ? -1 : ans) << endl;
}