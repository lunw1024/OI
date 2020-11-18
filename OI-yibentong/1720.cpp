#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, ll> P;

const int MAXN = 1001;
int N, M;
vector<P> edges[MAXN];
double dist[MAXN];

bool check(double k) {
    fill(dist + 1, dist + N, 1e10);
    dist[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (P e : edges[i]) {
            dist[e.first] = e.second;
        }
    }

    // bellman-ford
    bool out = false;
    for (int i = 1; i <= N; i++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            for (P e : edges[j]) {
                if (i == N && dist[j] > dist[e.first] + e.second - k)
                    out = true;
                if (dist[j] > dist[e.first] + e.second - k)
                    flag = false;
                dist[j] = min(dist[j], dist[e.first] + e.second - k);
            }
        }
        if (flag)
            break;
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;    
    for (int i = 1; i <= M; i++) {
        int a, b;
        double w;
        cin >> a >> b >> w;
        edges[a].push_back(make_pair(b, w));
    }

    double l = 0, r = 1e7;
    bool ans = false;
    while (r - l > 0.004) {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid, ans = true;
        else
            l = mid;
    }
    if (!ans)
        cout << "PaPaFish is laying egg!" << endl;
    else
        cout << setiosflags(ios::fixed) << setprecision(2) << r << endl;
}