#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, M;
string s;
int dist[(int)1e5 + 1];
vector<int> ans;

int main() {
    cin >> N >> M >> s;
    fill(dist, dist + N + 1, (int)1e9);
    dist[N] = 0;
    int p = N - 1;
    for (int i = N; i >= 0; i--) {
        if (s[i] == '1')
            continue;
        for (p = min(p, i - 1); p >= max(0, i - M); p--) {
            if (s[p] == '1')
                continue;
            dist[p] = min(dist[p], dist[i] + 1);
        }
    }
    
    if (dist[0] == (int)1e9) {
        cout << -1 << endl;
        return 0;
    }

    p = 0;
    while (p < N) {
        for (int i = p + 1; i <= min(N, p + M); i++) {
            if (dist[i] == dist[p] - 1) {
                ans.push_back(i - p);
                p = i;
                break;
            }
        }
    }

    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;
}